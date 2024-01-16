/*
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef NAV2_AMCL__AMCL_NODE_HPP_
#define NAV2_AMCL__AMCL_NODE_HPP_

#include <atomic>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "geometry_msgs/msg/pose_array.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "message_filters/subscriber.h"
#include "nav2_util/lifecycle_node.hpp"
#include "nav2_amcl/motion_model/motion_model.hpp"
#include "nav2_amcl/sensors/laser/laser.hpp"
#include "nav2_msgs/msg/particle.hpp"
#include "nav2_msgs/msg/particle_cloud.hpp"
#include "nav_msgs/srv/set_map.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_srvs/srv/empty.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wreorder"
#include "tf2_ros/message_filter.h"
#pragma GCC diagnostic pop

#define NEW_UNIFORM_SAMPLING 1

namespace nav2_amcl
{

class AmclNode : public nav2_util::LifecycleNode
{
public:
  AmclNode();
  ~AmclNode();

protected:
  // Implement the lifecycle interface
  nav2_util::CallbackReturn on_configure(const rclcpp_lifecycle::State & state) override;
  nav2_util::CallbackReturn on_activate(const rclcpp_lifecycle::State & state) override;
  nav2_util::CallbackReturn on_deactivate(const rclcpp_lifecycle::State & state) override;
  nav2_util::CallbackReturn on_cleanup(const rclcpp_lifecycle::State & state) override;
  nav2_util::CallbackReturn on_shutdown(const rclcpp_lifecycle::State & state) override;

  // Since the sensor data from gazebo or the robot is not lifecycle enabled, we won't
  // respond until we're in the active state
  std::atomic<bool> active_{false};

  // Pose hypothesis
  typedef struct
  {
    double weight;             // Total weight (weights sum to 1)
    pf_vector_t pf_pose_mean;  // Mean of pose esimate
    pf_matrix_t pf_pose_cov;   // Covariance of pose estimate
  } amcl_hyp_t;

  // Map-related
  void mapReceived(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);
  void handleMapMessage(const nav_msgs::msg::OccupancyGrid & msg);
  void createFreeSpaceVector();
  void freeMapDependentMemory();
  map_t * map_{nullptr};  //地图对象指针
  map_t * convertMap(const nav_msgs::msg::OccupancyGrid & map_msg);
  bool first_map_only_{true}; // 是否只接收第一帧地图,如果这个为真并且first_map_only_为真,那么地图就只会更新一次
  std::atomic<bool> first_map_received_{false}; //是否接收到地图,如果这个为真并且first_map_only_为真,那么地图就只会更新一次
  // 是在handleInitialPoseMessage()函数中对这个变量进行初始化的
  amcl_hyp_t * initial_pose_hyp_; //初始位姿假设,这个只有服务才会调用
  std::recursive_mutex configuration_mutex_;  //线程锁是一个类成员,因为都是类成员函数在用它
  rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::ConstSharedPtr map_sub_;
#if NEW_UNIFORM_SAMPLING
  static std::vector<std::pair<int, int>> free_space_indices; //地图的free区域
#endif

  // Transforms
  void initTransforms();
  std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  bool sent_first_transform_{false};  // 是否发送过坐标变换
  bool latest_tf_valid_{false};       // 坐标变换是否可用,就是只要权重和大于0,就会发布tf树
  tf2::Transform latest_tf_;          // 这个就是上odom下map
  void waitForTransforms();

  // Message filters
  void initMessageFilters();
  std::unique_ptr<message_filters::Subscriber<sensor_msgs::msg::LaserScan>> laser_scan_sub_;
  std::unique_ptr<tf2_ros::MessageFilter<sensor_msgs::msg::LaserScan>> laser_scan_filter_;
  message_filters::Connection laser_scan_connection_;

  // Publishers and subscribers
  void initPubSub();
  rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::ConstSharedPtr
    initial_pose_sub_;
  rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr
    pose_pub_;
  rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::PoseArray>::SharedPtr particlecloud_pub_;
  rclcpp_lifecycle::LifecyclePublisher<nav2_msgs::msg::ParticleCloud>::SharedPtr
    particle_cloud_pub_;
  void initialPoseReceived(geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg);
  void laserReceived(sensor_msgs::msg::LaserScan::ConstSharedPtr laser_scan);

  // Services and service callbacks
  void initServices();
  rclcpp::Service<std_srvs::srv::Empty>::SharedPtr global_loc_srv_;
  void globalLocalizationCallback(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<std_srvs::srv::Empty::Request> request,
    std::shared_ptr<std_srvs::srv::Empty::Response> response);

  // Let amcl update samples without requiring motion
  rclcpp::Service<std_srvs::srv::Empty>::SharedPtr nomotion_update_srv_;
  void nomotionUpdateCallback(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<std_srvs::srv::Empty::Request> request,
    std::shared_ptr<std_srvs::srv::Empty::Response> response);

  // Nomotion update control. Used to temporarily let amcl update samples even when no motion occurs
  std::atomic<bool> force_update_{false};

  // Odometry
  void initOdometry();
  std::unique_ptr<nav2_amcl::MotionModel> motion_model_;
  geometry_msgs::msg::PoseStamped latest_odom_pose_;
  geometry_msgs::msg::PoseWithCovarianceStamped last_published_pose_;
  double init_pose_[3]; // 初始的位姿
  double init_cov_[3];  // 初始的协方差
  bool getOdomPose(
    // Helper to get odometric pose from transform system
    geometry_msgs::msg::PoseStamped & pose,
    double & x, double & y, double & yaw,
    const rclcpp::Time & sensor_timestamp, const std::string & frame_id);
  std::atomic<bool> first_pose_sent_;

  // Particle filter
  void initParticleFilter();
  // Pose-generating function used to uniformly distribute particles over the map
  static pf_vector_t uniformPoseGenerator(void * arg);
  pf_t * pf_{nullptr};    // 地图对象指针
  std::mutex pf_mutex_;
  // 这个不是函数的初始化，这个是对pf_odom_pose_的初始化
  // 执行pf_init或者pf_init_model之后，也会把这个设置为false
  // 这个变量的作用就是给pf_odom_pose_进行初始值的赋值
  bool pf_init_;    // 没有初始化就是false
  pf_vector_t pf_odom_pose_;  // 上一时刻的里程计位姿,即上odom下base_link
  int resample_count_{0};     // 重采样计数

  // Laser scan related
  void initLaserScan();
  nav2_amcl::Laser * createLaserObject();
  int scan_error_count_{0};
  std::vector<nav2_amcl::Laser *> lasers_;  //记录下当前构建的雷达对象，
  //这个应该是说可以有多个传感器, 如果为true说明这个激光雷达的数据得到更新了,只有刷新了,才可以使用
  std::vector<bool> lasers_update_; //标记雷达的更新状态，可以多个传感器
  //通过一个string到int的map建立其雷达坐标ID到雷达对象在lasers_中的对应关系
  // 就是有多个激光雷达的时候，存储不同激光雷达的id
  std::map<std::string, int> frame_to_laser_; //存放激光源
  rclcpp::Time last_laser_received_ts_;       // 上一次结束到激光雷达数据的时间,为了判断激光雷达是否宕机
  void checkLaserReceived();
  std::chrono::seconds laser_check_interval_; // TODO(mjeronimo): not initialized

  bool checkElapsedTime(std::chrono::seconds check_interval, rclcpp::Time last_time);
  rclcpp::Time last_time_printed_msg_;

  bool addNewScanner(
    int & laser_index,
    const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
    const std::string & laser_scan_frame_id,
    geometry_msgs::msg::PoseStamped & laser_pose);
  bool shouldUpdateFilter(const pf_vector_t pose, pf_vector_t & delta);
  bool updateFilter(
    const int & laser_index,
    const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
    const pf_vector_t & pose);
  void publishParticleCloud(const pf_sample_set_t * set);
  bool getMaxWeightHyp(
    std::vector<amcl_hyp_t> & hyps, amcl_hyp_t & max_weight_hyps,
    int & max_weight_hyp);
  void publishAmclPose(
    const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
    const std::vector<amcl_hyp_t> & hyps, const int & max_weight_hyp);
  void calculateMaptoOdomTransform(
    const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
    const std::vector<amcl_hyp_t> & hyps,
    const int & max_weight_hyp);
  void sendMapToOdomTransform(const tf2::TimePoint & transform_expiration);
  void handleInitialPose(geometry_msgs::msg::PoseWithCovarianceStamped & msg);
  bool init_pose_received_on_inactive{false};
  bool initial_pose_is_known_{false};
  bool set_initial_pose_{false};
  bool always_reset_initial_pose_;
  double initial_pose_x_;
  double initial_pose_y_;
  double initial_pose_z_;
  double initial_pose_yaw_;

  // Node parameters (initialized via initParameters)
  void initParameters();
  double alpha1_;
  double alpha2_;
  double alpha3_;
  double alpha4_;
  double alpha5_;
  std::string base_frame_id_;
  double beam_skip_distance_;
  double beam_skip_error_threshold_;
  double beam_skip_threshold_;
  bool do_beamskip_;
  std::string global_frame_id_;
  double lambda_short_;
  double laser_likelihood_max_dist_;
  double laser_max_range_;
  // 激光雷达的最大距离，就是对激光雷达最大距离进行裁剪的
  // 如果超过这个值，激光雷达的最大距离就设置为这个值
  // 如果是-1，那么就不用管
  double laser_min_range_;
  std::string sensor_model_type_;
  int max_beams_;
  int max_particles_;
  int min_particles_;
  std::string odom_frame_id_;
  double pf_err_;
  double pf_z_;
  double alpha_fast_;
  double alpha_slow_;
  int resample_interval_;   // 多久进行一次重采样
  std::string robot_model_type_;
  tf2::Duration save_pose_period_;
  double sigma_hit_;
  bool tf_broadcast_;   // 是否发布tf树
  tf2::Duration transform_tolerance_;
  double a_thresh_;
  double d_thresh_;
  double z_hit_;
  double z_max_;
  double z_short_;
  double z_rand_;
  std::string scan_topic_{"scan"};
  std::string map_topic_{"map"};

  double lost_w_, poor_w_, poor_wdiff_, lost_m_, poor_m_;
  bool nomotion_en_;
  int nomotion_time_;
  double system_log;

};

}  // namespace nav2_amcl

#endif  // NAV2_AMCL__AMCL_NODE_HPP_
