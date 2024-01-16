// AMCL先根据里程计信息初步定位base_frame，然后通过测量模型得到base_frame相对于map_frame（全局地图坐标系），也就知道了机器人在地图中的位姿。
// （注意，这里虽然估计的是base到map的转换，但最后发布的是map到odom的转换，可以理解为里程计的漂移。）

#include "nav2_amcl/amcl_node.hpp"

#include <algorithm>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "message_filters/subscriber.h"
#include "nav2_amcl/angleutils.hpp"
#include "nav2_util/geometry_utils.hpp"
#include "nav2_amcl/pf/pf.hpp"
#include "nav2_util/string_utils.hpp"
#include "nav2_amcl/sensors/laser/laser.hpp"
#include "tf2/convert.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2/LinearMath/Transform.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/message_filter.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/create_timer_ros.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "tf2/utils.h"
#pragma GCC diagnostic pop

#include "portable_utils.h"

using namespace std::placeholders;
using namespace std::chrono_literals;

namespace nav2_amcl
{
using nav2_util::geometry_utils::orientationAroundZAxis;

AmclNode::AmclNode()
: nav2_util::LifecycleNode("amcl", "", true)
{
  RCLCPP_INFO(get_logger(), "Creating");

  add_parameter(
    "alpha1", rclcpp::ParameterValue(0.2),
    "This is the alpha1 parameter", "These are additional constraints for alpha1");

  add_parameter(
    "alpha2", rclcpp::ParameterValue(0.2),
    "This is the alpha2 parameter", "These are additional constraints for alpha2");

  add_parameter(
    "alpha3", rclcpp::ParameterValue(0.2),
    "This is the alpha3 parameter", "These are additional constraints for alpha3");

  add_parameter(
    "alpha4", rclcpp::ParameterValue(0.2),
    "This is the alpha4 parameter", "These are additional constraints for alpha4");

  add_parameter(
    "alpha5", rclcpp::ParameterValue(0.2),
    "This is the alpha5 parameter", "These are additional constraints for alpha5");

  add_parameter(
    "base_frame_id", rclcpp::ParameterValue(std::string("base_footprint")),
    "Which frame to use for the robot base");

  add_parameter("beam_skip_distance", rclcpp::ParameterValue(0.5));
  add_parameter("beam_skip_error_threshold", rclcpp::ParameterValue(0.9));
  add_parameter("beam_skip_threshold", rclcpp::ParameterValue(0.3));
  add_parameter("do_beamskip", rclcpp::ParameterValue(false));

  add_parameter(
    "global_frame_id", rclcpp::ParameterValue(std::string("map")),
    "The name of the coordinate frame published by the localization system");

  add_parameter(
    "lambda_short", rclcpp::ParameterValue(0.1),
    "Exponential decay parameter for z_short part of model");

  add_parameter(
    "laser_likelihood_max_dist", rclcpp::ParameterValue(2.0),
    "Maximum distance to do obstacle inflation on map, for use in likelihood_field model");

  add_parameter(
    "laser_max_range", rclcpp::ParameterValue(100.0),
    "Maximum scan range to be considered",
    "-1.0 will cause the laser's reported maximum range to be used");

  add_parameter(
    "laser_min_range", rclcpp::ParameterValue(-1.0),
    "Minimum scan range to be considered",
    "-1.0 will cause the laser's reported minimum range to be used");

  add_parameter(
    "laser_model_type", rclcpp::ParameterValue(std::string("likelihood_field")),
    "Which model to use, either beam, likelihood_field, or likelihood_field_prob",
    "Same as likelihood_field but incorporates the beamskip feature, if enabled");

  add_parameter(
    "set_initial_pose", rclcpp::ParameterValue(false),
    "Causes AMCL to set initial pose from the initial_pose* parameters instead of "
    "waiting for the initial_pose message");

  add_parameter(
    "initial_pose.x", rclcpp::ParameterValue(0.0),
    "X coordinate of the initial robot pose in the map frame");

  add_parameter(
    "initial_pose.y", rclcpp::ParameterValue(0.0),
    "Y coordinate of the initial robot pose in the map frame");

  add_parameter(
    "initial_pose.z", rclcpp::ParameterValue(0.0),
    "Z coordinate of the initial robot pose in the map frame");

  add_parameter(
    "initial_pose.yaw", rclcpp::ParameterValue(0.0),
    "Yaw of the initial robot pose in the map frame");

  add_parameter(
    "max_beams", rclcpp::ParameterValue(60),
    "How many evenly-spaced beams in each scan to be used when updating the filter");

  add_parameter(
    "max_particles", rclcpp::ParameterValue(2000),
    "Minimum allowed number of particles");

  add_parameter(
    "min_particles", rclcpp::ParameterValue(500),
    "Maximum allowed number of particles");

  add_parameter(
    "odom_frame_id", rclcpp::ParameterValue(std::string("odom")),
    "Which frame to use for odometry");

  add_parameter("pf_err", rclcpp::ParameterValue(0.05));
  add_parameter("pf_z", rclcpp::ParameterValue(0.99));

  add_parameter(
    "recovery_alpha_fast", rclcpp::ParameterValue(0.0),
    "Exponential decay rate for the fast average weight filter, used in deciding when to recover "
    "by adding random poses",
    "A good value might be 0.1");

  add_parameter(
    "recovery_alpha_slow", rclcpp::ParameterValue(0.0),
    "Exponential decay rate for the slow average weight filter, used in deciding when to recover "
    "by adding random poses",
    "A good value might be 0.001");

  add_parameter(
    "resample_interval", rclcpp::ParameterValue(1),
    "Number of filter updates required before resampling");

  add_parameter("robot_model_type", rclcpp::ParameterValue(std::string("differential")));

  add_parameter(
    "save_pose_rate", rclcpp::ParameterValue(0.5),
    "Maximum rate (Hz) at which to store the last estimated pose and covariance to the parameter "
    "server, in the variables ~initial_pose_* and ~initial_cov_*. This saved pose will be used "
    "on subsequent runs to initialize the filter",
    "-1.0 to disable");

  add_parameter("sigma_hit", rclcpp::ParameterValue(0.2));

  add_parameter(
    "tf_broadcast", rclcpp::ParameterValue(true),
    "Set this to false to prevent amcl from publishing the transform between the global frame and "
    "the odometry frame");

  add_parameter(
    "transform_tolerance", rclcpp::ParameterValue(1.0),
    "Time with which to post-date the transform that is published, to indicate that this transform "
    "is valid into the future");

  add_parameter(
    "update_min_a", rclcpp::ParameterValue(0.2),
    "Rotational movement required before performing a filter update");

  add_parameter(
    "update_min_d", rclcpp::ParameterValue(0.25),
    "Translational movement required before performing a filter update");

  add_parameter("z_hit", rclcpp::ParameterValue(0.5));
  add_parameter("z_max", rclcpp::ParameterValue(0.05));
  add_parameter("z_rand", rclcpp::ParameterValue(0.5));
  add_parameter("z_short", rclcpp::ParameterValue(0.05));

  add_parameter(
    "always_reset_initial_pose", rclcpp::ParameterValue(false),
    "Requires that AMCL is provided an initial pose either via topic or initial_pose* parameter "
    "(with parameter set_initial_pose: true) when reset. Otherwise, by default AMCL will use the"
    "last known pose to initialize");

  add_parameter(
    "scan_topic", rclcpp::ParameterValue("scan"),
    "Topic to subscribe to in order to receive the laser scan for localization");

  add_parameter(
    "map_topic", rclcpp::ParameterValue("map"),
    "Topic to subscribe to in order to receive the map to localize on");

  add_parameter("lost_w", rclcpp::ParameterValue(8.0));
  add_parameter("poor_w", rclcpp::ParameterValue(15.0));
  add_parameter("poor_wdiff", rclcpp::ParameterValue(8.0));
  add_parameter("lost_m", rclcpp::ParameterValue(0.6));
  add_parameter("poor_m", rclcpp::ParameterValue(6.0));

  add_parameter("nomotion_en", rclcpp::ParameterValue(true));
  add_parameter("nomotion_time", rclcpp::ParameterValue(2.0));
}

// //////////////////////    析构函数    //////////////////////////
AmclNode::~AmclNode()
{
  RCLCPP_INFO(get_logger(), "Destroying------------------------");
}

nav2_util::CallbackReturn
AmclNode::on_configure(const rclcpp_lifecycle::State & /*state*/)
{
  RCLCPP_INFO(get_logger(), "Configuring------------------------");

  initParameters();
  initTransforms();
  initMessageFilters();
  initPubSub();
  initServices();
  initOdometry();
  initParticleFilter();
  initLaserScan();

  return nav2_util::CallbackReturn::SUCCESS;
}

void
AmclNode::waitForTransforms()
{
  std::string tf_error;

  RCLCPP_INFO(get_logger(), "Checking that transform thread is ready");

  while (rclcpp::ok() &&
    !tf_buffer_->canTransform(
      global_frame_id_, odom_frame_id_, tf2::TimePointZero,
      transform_tolerance_, &tf_error))
  {
    RCLCPP_INFO(
      get_logger(), "Timed out waiting for transform from %s to %s"
      " to become available, tf error: %s",
      odom_frame_id_.c_str(), global_frame_id_.c_str(), tf_error.c_str());

    // The error string will accumulate and errors will typically be the same, so the last
    // will do for the warning above. Reset the string here to avoid accumulation.
    tf_error.clear();
  }
}

nav2_util::CallbackReturn
AmclNode::on_activate(const rclcpp_lifecycle::State & /*state*/)
{
  RCLCPP_INFO(get_logger(), "Activating------------------------");

  // Lifecycle publishers must be explicitly activated
  pose_pub_->on_activate();
  particlecloud_pub_->on_activate();
  particle_cloud_pub_->on_activate();

  RCLCPP_WARN(
    get_logger(),
    "Publishing the particle cloud as geometry_msgs/PoseArray msg is deprecated, "
    "will be published as nav2_msgs/ParticleCloud in the future");

  first_pose_sent_ = false;

  // Keep track of whether we're in the active state. We won't
  // process incoming callbacks until we are
  active_ = true;

  if (set_initial_pose_) {
    auto msg = std::make_shared<geometry_msgs::msg::PoseWithCovarianceStamped>();

    msg->header.stamp = now();
    msg->header.frame_id = global_frame_id_;
    msg->pose.pose.position.x = initial_pose_x_;
    msg->pose.pose.position.y = initial_pose_y_;
    msg->pose.pose.position.z = initial_pose_z_;
    msg->pose.pose.orientation = orientationAroundZAxis(initial_pose_yaw_);

    initialPoseReceived(msg);
  } else if (init_pose_received_on_inactive) {
    handleInitialPose(last_published_pose_);
  }

  return nav2_util::CallbackReturn::SUCCESS;
}

nav2_util::CallbackReturn
AmclNode::on_deactivate(const rclcpp_lifecycle::State & /*state*/)
{
  RCLCPP_INFO(get_logger(), "Deactivating------------------------");

  active_ = false;

  // Lifecycle publishers must be explicitly deactivated
  pose_pub_->on_deactivate();
  particlecloud_pub_->on_deactivate();
  particle_cloud_pub_->on_deactivate();

  return nav2_util::CallbackReturn::SUCCESS;
}

nav2_util::CallbackReturn
AmclNode::on_cleanup(const rclcpp_lifecycle::State & /*state*/)
{
  RCLCPP_INFO(get_logger(), "Cleaning up------------------------");

  // Get rid of the inputs first (services and message filter input), so we
  // don't continue to process incoming messages
  global_loc_srv_.reset();
  nomotion_update_srv_.reset();
  initial_pose_sub_.reset();
  laser_scan_connection_.disconnect();
  laser_scan_filter_.reset();
  laser_scan_sub_.reset();

  // Map
  map_free(map_);
  map_ = nullptr;
  first_map_received_ = false;
  free_space_indices.resize(0);

  // Transforms
  tf_broadcaster_.reset();
  tf_listener_.reset();
  tf_buffer_.reset();

  // PubSub
  pose_pub_.reset();
  particlecloud_pub_.reset();
  particle_cloud_pub_.reset();

  // Odometry
  motion_model_.reset();

  // Particle Filter
  pf_free(pf_);
  pf_ = nullptr;

  // Laser Scan
  lasers_.clear();
  lasers_update_.clear();
  frame_to_laser_.clear();
  force_update_ = true;

  if (set_initial_pose_) {
    set_parameter(
      rclcpp::Parameter(
        "initial_pose.x",
        rclcpp::ParameterValue(last_published_pose_.pose.pose.position.x)));
    set_parameter(
      rclcpp::Parameter(
        "initial_pose.y",
        rclcpp::ParameterValue(last_published_pose_.pose.pose.position.y)));
    set_parameter(
      rclcpp::Parameter(
        "initial_pose.z",
        rclcpp::ParameterValue(last_published_pose_.pose.pose.position.z)));
    set_parameter(
      rclcpp::Parameter(
        "initial_pose.yaw",
        rclcpp::ParameterValue(tf2::getYaw(last_published_pose_.pose.pose.orientation))));
  }

  return nav2_util::CallbackReturn::SUCCESS;
}

nav2_util::CallbackReturn
AmclNode::on_shutdown(const rclcpp_lifecycle::State & /*state*/)
{
  RCLCPP_INFO(get_logger(), "Shutting down");
  return nav2_util::CallbackReturn::SUCCESS;
}

// 每隔15s进去一次
void
AmclNode::checkLaserReceived()
{
  // RCLCPP_WARN(get_logger(), "checkLaserReceived");
  if (last_laser_received_ts_.nanoseconds() == 0) {
    RCLCPP_WARN(
      get_logger(), "Laser scan has not been received"
      " (and thus no pose updates have been published)."
      " Verify that data is being published on the %s topic.", scan_topic_.c_str());
    return;
  }

  // last_laser_received_ts_: 上一次结束到激光雷达数据的时间
  rclcpp::Duration d = now() - last_laser_received_ts_;
  if (d.nanoseconds() * 1e-9 > laser_check_interval_.count()) {
    RCLCPP_WARN(
      get_logger(), "No laser scan received (and thus no pose updates have been published) for %f"
      " seconds.  Verify that data is being published on the %s topic.",
      d.nanoseconds() * 1e-9, scan_topic_.c_str());
  }
}

bool
AmclNode::checkElapsedTime(std::chrono::seconds check_interval, rclcpp::Time last_time)
{
  rclcpp::Duration elapsed_time = now() - last_time;
  if (elapsed_time.nanoseconds() * 1e-9 > check_interval.count()) {
    return true;
  }
  return false;
}

#if NEW_UNIFORM_SAMPLING
std::vector<std::pair<int, int>> AmclNode::free_space_indices;
#endif

// /////////////////    得到机器人在里程计坐标系中的位置    ////////////
bool
AmclNode::getOdomPose(
  geometry_msgs::msg::PoseStamped & odom_pose,
  double & x, double & y, double & yaw,
  const rclcpp::Time & sensor_timestamp, const std::string & frame_id)
{
  //先取一个base坐标系内为单位变换的pose  Get the robot's pose  [***]
  geometry_msgs::msg::PoseStamped ident;
  ident.header.frame_id = nav2_util::strip_leading_slash(frame_id);
  ident.header.stamp = sensor_timestamp;
  tf2::toMsg(tf2::Transform::getIdentity(), ident.pose);

  // ////   将这个pose通过base_link和odom之间的坐标转换得到在odom中的表示
  try {
    // ident就是base_link
    tf_buffer_->transform(ident, odom_pose, odom_frame_id_);
  } catch (tf2::TransformException & e) {
    ++scan_error_count_;
    if (scan_error_count_ % 20 == 0) {
      RCLCPP_ERROR(
        get_logger(), "(%d) consecutive laser scan transforms failed: (%s)", scan_error_count_,
        e.what());
    }
    return false;
  }

  scan_error_count_ = 0;  // reset since we got a good transform
  x = odom_pose.pose.position.x;
  y = odom_pose.pose.position.y;
  yaw = tf2::getYaw(odom_pose.pose.orientation);

  return true;
}

// /////////////////////    空白区域均匀撒点    ////////////////////////
// 产生一个粒子点,然后返回这个粒子
pf_vector_t
AmclNode::uniformPoseGenerator(void * arg)
{
  map_t * map = reinterpret_cast<map_t *>(arg);

#if NEW_UNIFORM_SAMPLING
  unsigned int rand_index = drand48() * free_space_indices.size();
  std::pair<int, int> free_point = free_space_indices[rand_index];
  pf_vector_t p;
  //将点的地图坐标(格子数)转换为世界坐标(米)
  p.v[0] = MAP_WXGX(map, free_point.first);
  p.v[1] = MAP_WYGY(map, free_point.second);
  p.v[2] = drand48() * 2 * M_PI - M_PI;
#else
  double min_x, max_x, min_y, max_y;

  min_x = (map->size_x * map->scale) / 2.0 - map->origin_x;
  max_x = (map->size_x * map->scale) / 2.0 + map->origin_x;
  min_y = (map->size_y * map->scale) / 2.0 - map->origin_y;
  max_y = (map->size_y * map->scale) / 2.0 + map->origin_y;

  pf_vector_t p;

  RCLCPP_DEBUG(get_logger(), "Generating new uniform sample");
  for (;; ) {
    p.v[0] = min_x + drand48() * (max_x - min_x);
    p.v[1] = min_y + drand48() * (max_y - min_y);
    p.v[2] = drand48() * 2 * M_PI - M_PI;
    // Check that it's a free cell
    int i, j;
    i = MAP_GXWX(map, p.v[0]);
    j = MAP_GYWY(map, p.v[1]);
    if (MAP_VALID(map, i, j) && (map->cells[MAP_INDEX(map, i, j)].occ_state == -1)) {
      break;
    }
  }
#endif
  return p;
}

//调用pf_init_model，然后调用AmclNode::uniformPoseGenerator在地图的free点随机生成pf->max_samples个粒子
void
AmclNode::globalLocalizationCallback(
  const std::shared_ptr<rmw_request_id_t>/*request_header*/,
  const std::shared_ptr<std_srvs::srv::Empty::Request>/*req*/,
  std::shared_ptr<std_srvs::srv::Empty::Response>/*res*/)
{
  std::lock_guard<std::mutex> lock(pf_mutex_);

  RCLCPP_INFO(get_logger(), "Initializing with uniform distribution");

  pf_init_model(
    pf_, (pf_init_model_fn_t)AmclNode::uniformPoseGenerator,
    reinterpret_cast<void *>(map_));
  RCLCPP_INFO(get_logger(), "Global initialisation done!");
  initial_pose_is_known_ = true;
  pf_init_ = false;
}

// force nomotion updates (amcl updating without requiring motion)
// 没运动模型更新的情况下也暂时更新粒子群
void
AmclNode::nomotionUpdateCallback(
  const std::shared_ptr<rmw_request_id_t>/*request_header*/,
  const std::shared_ptr<std_srvs::srv::Empty::Request>/*req*/,
  std::shared_ptr<std_srvs::srv::Empty::Response>/*res*/)
{
  RCLCPP_INFO(get_logger(), "Requesting no-motion update");
  force_update_ = true;
}

void
AmclNode::initialPoseReceived(geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(pf_mutex_);

  // 检查frame_id
  RCLCPP_INFO(get_logger(), "initialPoseReceived");

  if (msg->header.frame_id == "") {
    // This should be removed at some point
    RCLCPP_WARN(
      get_logger(),
      "Received initial pose with empty frame_id. You should always supply a frame_id.");
    return;
  }
  if (nav2_util::strip_leading_slash(msg->header.frame_id) != global_frame_id_) {
    RCLCPP_WARN(
      get_logger(),
      "Ignoring initial pose in frame \"%s\"; initial poses must be in the global frame, \"%s\"",
      nav2_util::strip_leading_slash(msg->header.frame_id).c_str(),
      global_frame_id_.c_str());
    return;
  }
  // Overriding last published pose to initial pose
  last_published_pose_ = *msg;

  if (!active_) {
    init_pose_received_on_inactive = true;
    RCLCPP_WARN(
      get_logger(), "Received initial pose request, "
      "but AMCL is not yet in the active state");
    return;
  }
  handleInitialPose(*msg);
}

void
AmclNode::handleInitialPose(geometry_msgs::msg::PoseWithCovarianceStamped & msg)
{
  // In case the client sent us a pose estimate in the past, integrate the
  // intervening odometric change.
  geometry_msgs::msg::TransformStamped tx_odom;
  try {
    rclcpp::Time rclcpp_time = now();
    tf2::TimePoint tf2_time(std::chrono::nanoseconds(rclcpp_time.nanoseconds()));

    // Check if the transform is available
    tx_odom = tf_buffer_->lookupTransform(
      base_frame_id_, tf2_ros::fromMsg(msg.header.stamp),
      base_frame_id_, tf2_time, odom_frame_id_);
  } catch (tf2::TransformException & e) {
    // If we've never sent a transform, then this is normal, because the
    // global_frame_id_ frame doesn't exist.  We only care about in-time
    // transformation for on-the-move pose-setting, so ignoring this
    // startup condition doesn't really cost us anything.
    if (sent_first_transform_) {
      RCLCPP_WARN(get_logger(), "Failed to transform initial pose in time (%s)", e.what());
    }
    tf2::impl::Converter<false, true>::convert(tf2::Transform::getIdentity(), tx_odom.transform);
  }

  tf2::Transform tx_odom_tf2; // 上odom下base_link  
  tf2::impl::Converter<true, false>::convert(tx_odom.transform, tx_odom_tf2);

  tf2::Transform pose_old;
  tf2::impl::Converter<true, false>::convert(msg.pose.pose, pose_old);

  // pose_old是上map下odom
  // pose_new是上map下base_Link
  tf2::Transform pose_new = pose_old * tx_odom_tf2;

  // Transform into the global frame

  RCLCPP_INFO(
    get_logger(), "Setting pose (%.6f): %.3f %.3f %.3f",
    now().nanoseconds() * 1e-9,
    pose_new.getOrigin().x(),
    pose_new.getOrigin().y(),
    tf2::getYaw(pose_new.getRotation()));

  // Re-initialize the filter
  pf_vector_t pf_init_pose_mean = pf_vector_zero();
  pf_init_pose_mean.v[0] = pose_new.getOrigin().x();
  pf_init_pose_mean.v[1] = pose_new.getOrigin().y();
  pf_init_pose_mean.v[2] = tf2::getYaw(pose_new.getRotation());

  pf_matrix_t pf_init_pose_cov = pf_matrix_zero();
  // Copy in the covariance, converting from 6-D to 3-D
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      pf_init_pose_cov.m[i][j] = msg.pose.covariance[6 * i + j];
    }
  }

  pf_init_pose_cov.m[2][2] = msg.pose.covariance[6 * 5 + 5];

  pf_init(pf_, pf_init_pose_mean, pf_init_pose_cov);
  pf_init_ = false;
  init_pose_received_on_inactive = false;
  initial_pose_is_known_ = true;
}

//接收到激光数据后,进行处理的回调函数
//该函数以雷达扫描数据的指针为输入参数
void
AmclNode::laserReceived(sensor_msgs::msg::LaserScan::ConstSharedPtr laser_scan)
{
  // RCLCPP_INFO(get_logger(), "LaserReceived");
  std::lock_guard<std::mutex> lock(pf_mutex_);

  // Since the sensor data is continually being published by the simulator or robot,
  // we don't want our callbacks to fire until we're in the active state
  if (!active_) {return;}
  if (!first_map_received_) {
    if (checkElapsedTime(2s, last_time_printed_msg_)) {
      RCLCPP_WARN(get_logger(), "Waiting for map....");
      last_time_printed_msg_ = now();
    }
    return;
  }
    // following 4 lines, wyj 2020-04-14
    double secs = rclcpp::Clock().now().seconds();
    int nowSec = int(secs);  

    if ((nomotion_en_ == 1) && (force_update_ == 0) && (nowSec % nomotion_time_) == 1) {
        force_update_ = 1;
    }

  //用变量last_laser_received_ts_记录下当前的系统时间， 它用于判定是否长时间未接收到雷达数据
  std::string laser_scan_frame_id = nav2_util::strip_leading_slash(laser_scan->header.frame_id);
  last_laser_received_ts_ = now();  //记录接收时间
  int laser_index = -1;
  geometry_msgs::msg::PoseStamped laser_pose;

  // Do we have the base->base_laser Tx yet?
  // 第一次是会进去的（当只有一个传感器的时候）
  if (frame_to_laser_.find(laser_scan_frame_id) == frame_to_laser_.end()) {
    if (!addNewScanner(laser_index, laser_scan, laser_scan_frame_id, laser_pose)) {
      return;  // could not find transform
    }
  } else {
    // we have the laser pose, retrieve laser index
    // 我们有激光姿态，检索激光下标
    laser_index = frame_to_laser_[laser_scan->header.frame_id];
  }

  // Where was the robot when this scan was taken?
  // 获得base在激光雷达扫描时候相对于odom的相对位姿
  pf_vector_t pose; // 当前机器人位置上odom下base_Link
  // 就是得到机器人在里程计坐标系下的坐标，同时给latest_odom_pose_和pose赋值
  if (!getOdomPose(
      latest_odom_pose_, pose.v[0], pose.v[1], pose.v[2],
      laser_scan->header.stamp, base_frame_id_))
  {
    RCLCPP_ERROR(get_logger(), "Couldn't determine robot's pose associated with laser scan");
    return;
  }

  pf_vector_t delta = pf_vector_zero();
  bool force_publication = false;
  // 如果还没初始化完,也就是,如果滤波器刚一开始滤波,那就先进行一些初始赋值的工作
  // 第一次会进去或者pf_init()或者pf_init_model再一次执行之后
  if (!pf_init_) {
    // Pose at last filter update
    pf_odom_pose_ = pose;
    pf_init_ = true;

    //就是把雷达lasers_update_这里面的表示全部更新为发生运动
    for (unsigned int i = 0; i < lasers_update_.size(); i++) {
      lasers_update_[i] = true;
    }

    // 第一次要发布
    force_publication = true;
    // 第一次会进去,进行初始化
    resample_count_ = 0;
  } else {
    // Set the laser update flags
    if (shouldUpdateFilter(pose, delta)) {
      for (unsigned int i = 0; i < lasers_update_.size(); i++) {
        lasers_update_[i] = true;
      }
    }
    if (lasers_update_[laser_index]) {
      motion_model_->odometryUpdate(pf_, pose, delta);
    }
    force_update_ = false;
  }

  bool resampled = false;

  // If the robot has moved, update the filter 激光更新
  // 只有进行了位姿的更新之后，才可以进行权重的更新
  if (lasers_update_[laser_index]) {
    updateFilter(laser_index, laser_scan, pose);

    // Resample the particles
    // 根据重采样计数器和设定的阈值，触发对滤波器的重采样
    // 每收到多少帧激光进行一次重采样
    // 默认间隔两次激光数据重采样一次
    if (!(++resample_count_ % resample_interval_)) {
      // 按照一定的规则重采样粒子，包括前面说的失效恢复、粒子权重等，
      // 然后放入到kdtree，暂时先理解成关于位姿的二叉树，
      // 然后进行聚类，得到均值和方差等信息,
      // RCLCPP_INFO(get_logger(), "pf_update_resample+++++++++++++");
      pf_update_resample(pf_, map_);
      resampled = true;

      RCLCPP_INFO(get_logger(), "total_w: %f\n", pf_->total_w);
    }

    // 粒子集
    pf_sample_set_t * set = pf_->sets + pf_->current_set;
    RCLCPP_DEBUG(get_logger(), "Num samples: %d\n", set->sample_count);

    if (!force_update_) {
      publishParticleCloud(set);
    }
  }
  // 如果进行了重采样或者强制发布，那么就发布聚类后，最高的单峰的均值之类的数据
  // force_publication除了第一次,其他都是false
  // 这个只有几次才会进去
  if (resampled || force_publication || !first_pose_sent_) {
    amcl_hyp_t max_weight_hyps;
    std::vector<amcl_hyp_t> hyps;
    int max_weight_hyp = -1;
    if (getMaxWeightHyp(hyps, max_weight_hyps, max_weight_hyp)) {
      publishAmclPose(laser_scan, hyps, max_weight_hyp);
      calculateMaptoOdomTransform(laser_scan, hyps, max_weight_hyp);

      if (tf_broadcast_ == true) {
        // We want to send a transform that is good up until a
        // tolerance time so that odom can be used
        // 我们想要发送一个很好的转换，直到一个容忍时间，以便odom可以使用
        auto stamp = tf2_ros::fromMsg(laser_scan->header.stamp);
        tf2::TimePoint transform_expiration = stamp + transform_tolerance_;
        sendMapToOdomTransform(transform_expiration);
        sent_first_transform_ = true;
      }
    } else {
      RCLCPP_ERROR(get_logger(), "No pose!");
    }
  } else if (latest_tf_valid_) {
    if (tf_broadcast_ == true) {
      // Nothing changed, so we'll just republish the last transform, to keep
      // everybody happy.
      tf2::TimePoint transform_expiration = tf2_ros::fromMsg(laser_scan->header.stamp) +
        transform_tolerance_;
      sendMapToOdomTransform(transform_expiration);
    }
  }
}

bool AmclNode::addNewScanner(
  int & laser_index,
  const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
  const std::string & laser_scan_frame_id,
  geometry_msgs::msg::PoseStamped & laser_pose)
{
  // 存放激光源
  lasers_.push_back(createLaserObject());
  lasers_update_.push_back(true);
  laser_index = frame_to_laser_.size();

  geometry_msgs::msg::PoseStamped ident;
  ident.header.frame_id = laser_scan_frame_id;
  ident.header.stamp = rclcpp::Time();
  // 设置ident值，设置为单位矩阵，即0
  tf2::toMsg(tf2::Transform::getIdentity(), ident.pose);
  try {
    // laser_pose：上base_Link下laser_link
    tf_buffer_->transform(ident, laser_pose, base_frame_id_, transform_tolerance_);
  } catch (tf2::TransformException & e) {
    RCLCPP_ERROR(
      get_logger(), "Couldn't transform from %s to %s, "
      "even though the message notifier is in use: (%s)",
      laser_scan->header.frame_id.c_str(),
      base_frame_id_.c_str(), e.what());
    return false;
  }

  // 上base_Link下laser_link
  pf_vector_t laser_pose_v;
  laser_pose_v.v[0] = laser_pose.pose.position.x;
  laser_pose_v.v[1] = laser_pose.pose.position.y;
  // laser mounting angle gets computed later -> set to 0 here!
  laser_pose_v.v[2] = 0;
  // 设置激光雷达在机器人中的位姿
  lasers_[laser_index]->SetLaserPose(laser_pose_v);
  frame_to_laser_[laser_scan->header.frame_id] = laser_index;
  return true;
}

bool AmclNode::shouldUpdateFilter(const pf_vector_t pose, pf_vector_t & delta)
{
  // Compute change in pose
  // delta = pf_vector_coord_sub(pose, pf_odom_pose_);
  // 计算delta值
  // 这个就是本时刻的里程计模型减去上一时刻的里程计模型
  // 也就是delta_x=/x'-/x,这里面的/就是x头上的——
  // pose和pf_odom_pose_：上odom下base_Link
  delta.v[0] = pose.v[0] - pf_odom_pose_.v[0];
  delta.v[1] = pose.v[1] - pf_odom_pose_.v[1];
  delta.v[2] = angleutils::angle_diff(pose.v[2], pf_odom_pose_.v[2]);

  // See if we should update the filter
  // 只有其中一个大于，才可以更新
  bool update = fabs(delta.v[0]) > d_thresh_ ||
    fabs(delta.v[1]) > d_thresh_ ||
    fabs(delta.v[2]) > a_thresh_;
  // m_force_update没运动模型更新的情况下也暂时更新粒子群
  update = update || force_update_;
  return update;
}

bool AmclNode::updateFilter(
  const int & laser_index,
  const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
  const pf_vector_t & pose)
{
  nav2_amcl::LaserData ldata;
  // 并指定传感器对象和量程
  ldata.laser = lasers_[laser_index];
  // 根据激光点的数量对大小进行设置
  ldata.range_count = laser_scan->ranges.size();

  // To account for lasers that are mounted upside-down, we determine the
  // min, max, and increment angles of the laser in the base frame.
  //
  // Construct min and max angles of laser, in the base_link frame.
  // Here we set the roll pich yaw of the lasers.  We assume roll and pich are zero.
  // 先将相对雷达自身角度tf2::convert为四元数-->通过tf将角度转移到base坐标系-->算出在base中的角度
  geometry_msgs::msg::QuaternionStamped min_q, inc_q;
  min_q.header.stamp = laser_scan->header.stamp;
  min_q.header.frame_id = nav2_util::strip_leading_slash(laser_scan->header.frame_id);
  min_q.quaternion = orientationAroundZAxis(laser_scan->angle_min);

  inc_q.header = min_q.header;
  inc_q.quaternion = orientationAroundZAxis(laser_scan->angle_min + laser_scan->angle_increment);
  try {
    // 上base_link下laser_link
    tf_buffer_->transform(min_q, min_q, base_frame_id_);  // 将四元数(角度)转换到base坐标系
    tf_buffer_->transform(inc_q, inc_q, base_frame_id_);
  } catch (tf2::TransformException & e) {
    RCLCPP_WARN(
      get_logger(), "Unable to transform min/max laser angles into base frame: %s",
      e.what());
    return false;
  }
  double angle_min = tf2::getYaw(min_q.quaternion);
  double angle_increment = tf2::getYaw(inc_q.quaternion) - angle_min;

  // wrapping angle to [-pi .. pi]将任意角度换算为-pi~pi区间内
  angle_increment = fmod(angle_increment + 5 * M_PI, 2 * M_PI) - M_PI;

  RCLCPP_DEBUG(
    get_logger(), "Laser %d angles in base frame: min: %.3f inc: %.3f", laser_index, angle_min,
    angle_increment);

  // Apply range min/max thresholds, if the user supplied them
  if (laser_max_range_ > 0.0) {
    ldata.range_max = std::min(laser_scan->range_max, static_cast<float>(laser_max_range_));
  } else {
    ldata.range_max = laser_scan->range_max;
  }
  double range_min;
  if (laser_min_range_ > 0.0) {
    range_min = std::max(laser_scan->range_min, static_cast<float>(laser_min_range_));
  } else {
    range_min = laser_scan->range_min;
  }

  // The LaserData destructor will free this memory
  // [2]:0激光测到的长度和1该束激光的角度
  ldata.ranges = new double[ldata.range_count][2];
  // 将激光数据放入到ldata中
  for (int i = 0; i < ldata.range_count; i++) {
    // amcl doesn't (yet) have a concept of min range.  So we'll map short
    // readings to max range.
    if (laser_scan->ranges[i] <= range_min) {
      ldata.ranges[i][0] = ldata.range_max;
    } else {
      ldata.ranges[i][0] = laser_scan->ranges[i];
    }
    // Compute bearing
    ldata.ranges[i][1] = angle_min + (i * angle_increment);
  }
  // 观测模型 更新权重
  // 用于根据传感器模型（自己给）和数据来更新粒子滤波器每个粒子（代表一个位姿）的权重，然后返回所有粒子权重的总和。
  lasers_[laser_index]->sensorUpdate(pf_, reinterpret_cast<nav2_amcl::LaserData *>(&ldata));
  // 然后清除lasers_update_的标记，并更新滤波器的里程计位姿。
  lasers_update_[laser_index] = false;
  // 这个就是更新数据，用此时刻去覆盖上一时刻
  pf_odom_pose_ = pose;
  return true;
}

void
AmclNode::publishParticleCloud(const pf_sample_set_t * set)
{
  // If initial pose is not known, AMCL does not know the current pose
  if (!initial_pose_is_known_) {return;}
  auto cloud_with_weights_msg = std::make_unique<nav2_msgs::msg::ParticleCloud>();
  cloud_with_weights_msg->header.stamp = this->now();
  cloud_with_weights_msg->header.frame_id = global_frame_id_;
  cloud_with_weights_msg->particles.resize(set->sample_count);

  auto cloud_msg = std::make_unique<geometry_msgs::msg::PoseArray>();
  cloud_msg->header.stamp = this->now();
  cloud_msg->header.frame_id = global_frame_id_;
  cloud_msg->poses.resize(set->sample_count);
  for (int i = 0; i < set->sample_count; i++) {
    cloud_msg->poses[i].position.x = set->samples[i].pose.v[0];
    cloud_msg->poses[i].position.y = set->samples[i].pose.v[1];
    cloud_msg->poses[i].position.z = 0;
    cloud_msg->poses[i].orientation = orientationAroundZAxis(set->samples[i].pose.v[2]);
    cloud_with_weights_msg->particles[i].pose = (*cloud_msg).poses[i];
    cloud_with_weights_msg->particles[i].weight = set->samples[i].weight;
  }
  // 发布话题为particlecloud的话题
  particlecloud_pub_->publish(std::move(cloud_msg));
  particle_cloud_pub_->publish(std::move(cloud_with_weights_msg));
}

bool
AmclNode::getMaxWeightHyp(
  std::vector<amcl_hyp_t> & hyps, amcl_hyp_t & max_weight_hyps,
  int & max_weight_hyp)
{
  // Read out the current hypotheses
  double max_weight = 0.0;
  hyps.resize(pf_->sets[pf_->current_set].cluster_count);
  // 读出每一个簇的统计数据，进行聚类后，有很多单峰，对这些单峰进行遍历
  for (int hyp_count = 0;
    hyp_count < pf_->sets[pf_->current_set].cluster_count; hyp_count++)
  {
    double weight;
    pf_vector_t pose_mean;
    pf_matrix_t pose_cov;
    if (!pf_get_cluster_stats(pf_, hyp_count, &weight, &pose_mean, &pose_cov)) {
      RCLCPP_ERROR(get_logger(), "Couldn't get stats on cluster %d", hyp_count);
      return false;
    }

    // 得到粒子集中单峰的权重均值和协方差
    hyps[hyp_count].weight = weight;
    hyps[hyp_count].pf_pose_mean = pose_mean;
    hyps[hyp_count].pf_pose_cov = pose_cov;
    // 权重最大的簇的信息
    // 找到权重最大的单峰
    // 这个就是最可能的位姿
    if (hyps[hyp_count].weight > max_weight) {
      max_weight = hyps[hyp_count].weight;
      max_weight_hyp = hyp_count;
    }
  }

  if (max_weight > 0.0) {
    RCLCPP_DEBUG(
      get_logger(), "Max weight pose: %.3f %.3f %.3f",
      hyps[max_weight_hyp].pf_pose_mean.v[0],
      hyps[max_weight_hyp].pf_pose_mean.v[1],
      hyps[max_weight_hyp].pf_pose_mean.v[2]);

    max_weight_hyps = hyps[max_weight_hyp];
    return true;
  }
  return false;
}

void
AmclNode::publishAmclPose(
  const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
  const std::vector<amcl_hyp_t> & hyps, const int & max_weight_hyp)
{
  // If initial pose is not known, AMCL does not know the current pose
  if (!initial_pose_is_known_) {
    if (checkElapsedTime(2s, last_time_printed_msg_)) {
      RCLCPP_WARN(
        get_logger(), "ACML cannot publish a pose or update the transform. "
        "Please set the initial pose...");
      last_time_printed_msg_ = now();
    }
    return;
  }

  //发布amcl_pose消息,消息的位姿信息是权重最大的簇的信息,协方差矩阵是全部粒子的协方差
  auto p = std::make_unique<geometry_msgs::msg::PoseWithCovarianceStamped>();
  // Fill in the header
  p->header.frame_id = global_frame_id_;
  p->header.stamp = laser_scan->header.stamp;
  // Copy in the pose
  p->pose.pose.position.x = hyps[max_weight_hyp].pf_pose_mean.v[0];
  p->pose.pose.position.y = hyps[max_weight_hyp].pf_pose_mean.v[1];
  p->pose.pose.orientation = orientationAroundZAxis(hyps[max_weight_hyp].pf_pose_mean.v[2]);
  // Copy in the covariance, converting from 3-D to 6-D
  pf_sample_set_t * set = pf_->sets + pf_->current_set;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      // Report the overall filter covariance, rather than the
      // covariance for the highest-weight cluster
      // p->covariance[6*i+j] = hyps[max_weight_hyp].pf_pose_cov.m[i][j];
      p->pose.covariance[6 * i + j] = set->cov.m[i][j];
    }
  }
  p->pose.covariance[6 * 5 + 5] = set->cov.m[2][2];
  float temp = 0.0;
  for (auto covariance_value : p->pose.covariance) {
    temp += covariance_value;
  }
  temp += p->pose.pose.position.x + p->pose.pose.position.y;
  if (!std::isnan(temp)) {
    RCLCPP_DEBUG(get_logger(), "Publishing pose");
    last_published_pose_ = *p;
    first_pose_sent_ = true;
    pose_pub_->publish(std::move(p));
  } else {
    RCLCPP_WARN(
      get_logger(), "AMCL covariance or pose is NaN, likely due to an invalid "
      "configuration or faulty sensor measurements! Pose is not available!");
  }

  RCLCPP_DEBUG(
    get_logger(), "New pose: %6.3f %6.3f %6.3f",
    hyps[max_weight_hyp].pf_pose_mean.v[0],
    hyps[max_weight_hyp].pf_pose_mean.v[1],
    hyps[max_weight_hyp].pf_pose_mean.v[2]);
}

void
AmclNode::calculateMaptoOdomTransform(
  const sensor_msgs::msg::LaserScan::ConstSharedPtr & laser_scan,
  const std::vector<amcl_hyp_t> & hyps, const int & max_weight_hyp)
{
  // subtracting base to odom from map to base and send map to odom instead
  geometry_msgs::msg::PoseStamped odom_to_map;
  // map～base减去odom～base得到map～odom，最后发布的是map～odom。
  try {
    // 定位得到的pose换算得到tf
    tf2::Quaternion q;
    q.setRPY(0, 0, hyps[max_weight_hyp].pf_pose_mean.v[2]);
    tf2::Transform tmp_tf(q, tf2::Vector3(
        hyps[max_weight_hyp].pf_pose_mean.v[0],
        hyps[max_weight_hyp].pf_pose_mean.v[1],
        0.0));

    // 将地图相对pose的tf toMsg 为消息
    geometry_msgs::msg::PoseStamped tmp_tf_stamped;
    tmp_tf_stamped.header.frame_id = base_frame_id_;
    tmp_tf_stamped.header.stamp = laser_scan->header.stamp;
    // tmp_tf.inverse()就是把tmp_tf_stamped中的frame_id由base_frame_id_转化为global_frame_id_
    tf2::toMsg(tmp_tf.inverse(), tmp_tf_stamped.pose);

    //将地图相对pose的消息换算到odom坐标系上去
    // 上odom下map
    tf_buffer_->transform(tmp_tf_stamped, odom_to_map, odom_frame_id_);
  } catch (tf2::TransformException & e) {
    RCLCPP_DEBUG(get_logger(), "Failed to subtract base to odom transform: (%s)", e.what());
    return;
  }

  //odom_to_map:上odom下map
  tf2::impl::Converter<true, false>::convert(odom_to_map.pose, latest_tf_);
  latest_tf_valid_ = true;
}

void
AmclNode::sendMapToOdomTransform(const tf2::TimePoint & transform_expiration)
{
  // AMCL will update transform only when it has knowledge about robot's initial position
  if (!initial_pose_is_known_) {return;}
  geometry_msgs::msg::TransformStamped tmp_tf_stamped;
  tmp_tf_stamped.header.frame_id = global_frame_id_;
  tmp_tf_stamped.header.stamp = tf2_ros::toMsg(transform_expiration);
  tmp_tf_stamped.child_frame_id = odom_frame_id_;
  tf2::impl::Converter<false, true>::convert(latest_tf_.inverse(), tmp_tf_stamped.transform);
  // tmp_tf_stamped就是上map下odom
  tf_broadcaster_->sendTransform(tmp_tf_stamped);
}

nav2_amcl::Laser *
AmclNode::createLaserObject()
{
  RCLCPP_INFO(get_logger(), "createLaserObject");

  if (sensor_model_type_ == "beam") {
    return new nav2_amcl::BeamModel(
      z_hit_, z_short_, z_max_, z_rand_, sigma_hit_, lambda_short_,
      0.0, max_beams_, map_);
  }

  if (sensor_model_type_ == "likelihood_field_prob") {
    return new nav2_amcl::LikelihoodFieldModelProb(
      z_hit_, z_rand_, sigma_hit_,
      laser_likelihood_max_dist_, do_beamskip_, beam_skip_distance_, beam_skip_threshold_,
      beam_skip_error_threshold_, max_beams_, map_);
  }

  return new nav2_amcl::LikelihoodFieldModel(
    z_hit_, z_rand_, sigma_hit_,
    laser_likelihood_max_dist_, max_beams_, map_);
}

void
AmclNode::initParameters()
{
  double save_pose_rate;
  double tmp_tol;

  get_parameter("alpha1", alpha1_);
  get_parameter("alpha2", alpha2_);
  get_parameter("alpha3", alpha3_);
  get_parameter("alpha4", alpha4_);
  get_parameter("alpha5", alpha5_);
  get_parameter("base_frame_id", base_frame_id_);
  get_parameter("beam_skip_distance", beam_skip_distance_);
  get_parameter("beam_skip_error_threshold", beam_skip_error_threshold_);
  get_parameter("beam_skip_threshold", beam_skip_threshold_);
  get_parameter("do_beamskip", do_beamskip_);
  get_parameter("global_frame_id", global_frame_id_);
  get_parameter("lambda_short", lambda_short_);
  get_parameter("laser_likelihood_max_dist", laser_likelihood_max_dist_);
  get_parameter("laser_max_range", laser_max_range_);
  get_parameter("laser_min_range", laser_min_range_);
  get_parameter("laser_model_type", sensor_model_type_);
  get_parameter("set_initial_pose", set_initial_pose_);
  get_parameter("initial_pose.x", initial_pose_x_);
  get_parameter("initial_pose.y", initial_pose_y_);
  get_parameter("initial_pose.z", initial_pose_z_);
  get_parameter("initial_pose.yaw", initial_pose_yaw_);
  get_parameter("max_beams", max_beams_);
  get_parameter("max_particles", max_particles_);
  get_parameter("min_particles", min_particles_);
  get_parameter("odom_frame_id", odom_frame_id_);
  get_parameter("pf_err", pf_err_);
  get_parameter("pf_z", pf_z_);
  get_parameter("recovery_alpha_fast", alpha_fast_);
  get_parameter("recovery_alpha_slow", alpha_slow_);
  get_parameter("resample_interval", resample_interval_);
  get_parameter("robot_model_type", robot_model_type_);
  get_parameter("save_pose_rate", save_pose_rate);
  get_parameter("sigma_hit", sigma_hit_);
  get_parameter("tf_broadcast", tf_broadcast_);
  get_parameter("transform_tolerance", tmp_tol);
  get_parameter("update_min_a", a_thresh_);
  get_parameter("update_min_d", d_thresh_);
  get_parameter("z_hit", z_hit_);
  get_parameter("z_max", z_max_);
  get_parameter("z_rand", z_rand_);
  get_parameter("z_short", z_short_);
  get_parameter("first_map_only_", first_map_only_);
  get_parameter("always_reset_initial_pose", always_reset_initial_pose_);
  get_parameter("scan_topic", scan_topic_);
  get_parameter("map_topic", map_topic_);

  get_parameter("lost_w", lost_w_);
  get_parameter("poor_w", poor_w_);
  get_parameter("poor_wdiff", poor_wdiff_);
  get_parameter("lost_m", lost_m_);
  get_parameter("poor_m", poor_m_);

  get_parameter("nomotion_en", nomotion_en_);
  get_parameter("nomotion_time", nomotion_time_);

  save_pose_period_ = tf2::durationFromSec(1.0 / save_pose_rate);
  transform_tolerance_ = tf2::durationFromSec(tmp_tol);

  odom_frame_id_ = nav2_util::strip_leading_slash(odom_frame_id_);
  base_frame_id_ = nav2_util::strip_leading_slash(base_frame_id_);
  global_frame_id_ = nav2_util::strip_leading_slash(global_frame_id_);

  last_time_printed_msg_ = now();

  // Semantic checks

  if (min_particles_ > max_particles_) {
    RCLCPP_WARN(
      get_logger(), "You've set min_particles to be greater than max particles,"
      " this isn't allowed so max_particles will be set to min_particles.");
    max_particles_ = min_particles_;
  }

  if (always_reset_initial_pose_) {
    initial_pose_is_known_ = false;
  }
}

void
AmclNode::mapReceived(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
  RCLCPP_DEBUG(get_logger(), "AmclNode: A new map was received.");
  if (first_map_only_ && first_map_received_) {
    return;
  }
  // 它以地图数据消息的引用为输入参数构建了地图对象，里程计对象和雷达传感器对象，并完成了滤波器的初始化工作。
  handleMapMessage(*msg);
  first_map_received_ = true;
}

// ///////////////////////  处理地图消息    ///////////////////////
//主题"map"的回调函数mapReceived，以及请求"static_map"服务的requestMap在接收到地图数据之后，
//都会调用函数handleMapMessage进一步完成AmclNode的初始化工作
//它以地图数据消息的引用为输入参数构建了地图对象，里程计对象和雷达传感器对象，并完成了滤波器的初始化工作。
void
AmclNode::handleMapMessage(const nav_msgs::msg::OccupancyGrid & msg)
{
  //下面一大堆处理信息不用管
  //对配置信号加锁，防止动态配置改动
  std::lock_guard<std::recursive_mutex> cfl(configuration_mutex_);

  RCLCPP_INFO(
    get_logger(), "Received a %d X %d map @ %.3f m/pix",
    msg.info.width,
    msg.info.height,
    msg.info.resolution);
  if (msg.header.frame_id != global_frame_id_) {
    RCLCPP_WARN(
      get_logger(), "Frame_id of map received:'%s' doesn't match global_frame_id:'%s'. This could"
      " cause issues with reading published topics",
      msg.header.frame_id.c_str(),
      global_frame_id_.c_str());
  }
  // 删除各个指针:地图,观测模型,运动模型等等
  freeMapDependentMemory();
  // ///   地图格式转换:消息-->结构体
  //转换成标准地图，-1(不是障碍);+1（障碍）;0（不明）
  map_ = convertMap(msg);

  //如果需要均匀分布的点，就将空闲栅格记录下来 Index of free space
  //就是把不是障碍的cell放进到free_space_indices里面
#if NEW_UNIFORM_SAMPLING
  createFreeSpaceVector();
#endif
}

void
AmclNode::createFreeSpaceVector()
{
  // Index of free space
  free_space_indices.resize(0);
  for (int i = 0; i < map_->size_x; i++) {
    for (int j = 0; j < map_->size_y; j++) {
      if (map_->cells[MAP_INDEX(map_, i, j)].occ_state == -1) {
        free_space_indices.push_back(std::make_pair(i, j));
      }
    }
  }
}

// 删除各个指针:地图,观测模型,运动模型等等
void
AmclNode::freeMapDependentMemory()
{
  if (map_ != NULL) {
    map_free(map_); //删掉为地图所开辟的内存
    map_ = NULL;    //地图指针指向空
  }

  // Clear queued laser objects because they hold pointers to the existing
  // map, #5202.
  lasers_.clear();
  lasers_update_.clear();
  frame_to_laser_.clear();
}

// /////////////////////   将地图消息转换为可处理的格式   ///////////////////////////
//转换成标准地图，-1(不是障碍);+1（障碍）;0（不明）
map_t *
AmclNode::convertMap(const nav_msgs::msg::OccupancyGrid & map_msg)
{
  map_t * map = map_alloc();

  //就是设置map的大小，分辨率还有机器人的起始位置
  map->size_x = map_msg.info.width;
  map->size_y = map_msg.info.height;
  map->scale = map_msg.info.resolution;
  map->origin_x = map_msg.info.origin.position.x + (map->size_x / 2) * map->scale;
  map->origin_y = map_msg.info.origin.position.y + (map->size_y / 2) * map->scale;
  
  //就是为map开辟地方
  //这个cells是n维一列的
  map->cells =
    reinterpret_cast<map_cell_t *>(malloc(sizeof(map_cell_t) * map->size_x * map->size_y));

  // Convert to player format
  //转换成标准地图，0->-1(不是障碍);100->+1（障碍）;else->0（不明）
  for (int i = 0; i < map->size_x * map->size_y; i++) {
    if (map_msg.data[i] == 0) {
      map->cells[i].occ_state = -1;
    } else if (map_msg.data[i] == 100) {  //这个和costmap中的不一样,发不出来的100对应的就是254(255)
      map->cells[i].occ_state = +1;
    } else {
      map->cells[i].occ_state = 0;
    }
  }

  return map;
}

void
AmclNode::initTransforms()
{
  RCLCPP_INFO(get_logger(), "initTransforms");

  // Initialize transform listener and broadcaster
  tf_buffer_ = std::make_shared<tf2_ros::Buffer>(rclcpp_node_->get_clock());
  auto timer_interface = std::make_shared<tf2_ros::CreateTimerROS>(
    rclcpp_node_->get_node_base_interface(),
    rclcpp_node_->get_node_timers_interface());
  tf_buffer_->setCreateTimerInterface(timer_interface);
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
  tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(rclcpp_node_);

  sent_first_transform_ = false;
  latest_tf_valid_ = false;
  latest_tf_ = tf2::Transform::getIdentity();
}

void
AmclNode::initMessageFilters()
{
  laser_scan_sub_ = std::make_unique<message_filters::Subscriber<sensor_msgs::msg::LaserScan>>(
    rclcpp_node_.get(), scan_topic_, rmw_qos_profile_sensor_data);

  laser_scan_filter_ = std::make_unique<tf2_ros::MessageFilter<sensor_msgs::msg::LaserScan>>(
    *laser_scan_sub_, *tf_buffer_, odom_frame_id_, 10, rclcpp_node_, transform_tolerance_);

  laser_scan_connection_ = laser_scan_filter_->registerCallback(
    std::bind(
      &AmclNode::laserReceived,
      this, std::placeholders::_1));
}

void
AmclNode::initPubSub()
{
  RCLCPP_INFO(get_logger(), "initPubSub");

  particlecloud_pub_ = create_publisher<geometry_msgs::msg::PoseArray>(
    "particlecloud",
    rclcpp::SensorDataQoS());

  particle_cloud_pub_ = create_publisher<nav2_msgs::msg::ParticleCloud>(
    "particle_cloud",
    rclcpp::SensorDataQoS());

  pose_pub_ = create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(
    "amcl_pose",
    rclcpp::QoS(rclcpp::KeepLast(1)).transient_local().reliable());

  initial_pose_sub_ = create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
    "initialpose", rclcpp::SystemDefaultsQoS(),
    std::bind(&AmclNode::initialPoseReceived, this, std::placeholders::_1));

  map_sub_ = create_subscription<nav_msgs::msg::OccupancyGrid>(
    map_topic_, rclcpp::QoS(rclcpp::KeepLast(1)).transient_local().reliable(),
    std::bind(&AmclNode::mapReceived, this, std::placeholders::_1));

  RCLCPP_INFO(get_logger(), "Subscribed to map topic.");
}

void
AmclNode::initServices()
{
  global_loc_srv_ = create_service<std_srvs::srv::Empty>(
    "reinitialize_global_localization",
    std::bind(&AmclNode::globalLocalizationCallback, this, _1, _2, _3));

  nomotion_update_srv_ = create_service<std_srvs::srv::Empty>(
    "request_nomotion_update",
    std::bind(&AmclNode::nomotionUpdateCallback, this, _1, _2, _3));
}

void
AmclNode::initOdometry()
{
  // TODO(mjeronimo): We should handle persistance of the last known pose of the robot. We could
  // then read that pose here and initialize using that.

  // When pausing and resuming, remember the last robot pose so we don't start at 0:0 again
  init_pose_[0] = last_published_pose_.pose.pose.position.x;
  init_pose_[1] = last_published_pose_.pose.pose.position.y;
  init_pose_[2] = tf2::getYaw(last_published_pose_.pose.pose.orientation);

  if (!initial_pose_is_known_) {
    init_cov_[0] = 0.5 * 0.5;
    init_cov_[1] = 0.5 * 0.5;
    init_cov_[2] = (M_PI / 12.0) * (M_PI / 12.0);
  } else {
    init_cov_[0] = last_published_pose_.pose.covariance[0];
    init_cov_[1] = last_published_pose_.pose.covariance[7];
    init_cov_[2] = last_published_pose_.pose.covariance[35];
  }

  motion_model_ = std::unique_ptr<nav2_amcl::MotionModel>(
    nav2_amcl::MotionModel::createMotionModel(
      robot_model_type_, alpha1_, alpha2_, alpha3_, alpha4_, alpha5_));

  latest_odom_pose_ = geometry_msgs::msg::PoseStamped();
}

void
AmclNode::initParticleFilter()
{  
  //创建一个滤波器
  //接着构建粒子滤波器对象，并完成初始化（产生随机点）
  //参数random_pose_fn是一个函数指针，提供了生成随机样本的函数，
  //amcl中使用的是AmclNode::uniformPoseGenerator，产生随机的粒子点
  //对于参数random_pose_data是粒子的样本空间， amcl实际使用的是地图对象。
  pf_ = pf_alloc(
    min_particles_, max_particles_, lost_w_, poor_w_, lost_m_, poor_m_, poor_wdiff_,
    alpha_slow_, alpha_fast_,
    (pf_init_model_fn_t)AmclNode::uniformPoseGenerator,
    reinterpret_cast<void *>(map_));
  pf_->pop_err = pf_err_;
  pf_->pop_z = pf_z_;

  // Initialize the filter
  pf_vector_t pf_init_pose_mean = pf_vector_zero();
  pf_init_pose_mean.v[0] = init_pose_[0];
  pf_init_pose_mean.v[1] = init_pose_[1];
  pf_init_pose_mean.v[2] = init_pose_[2];

  pf_matrix_t pf_init_pose_cov = pf_matrix_zero();
  pf_init_pose_cov.m[0][0] = init_cov_[0];
  pf_init_pose_cov.m[1][1] = init_cov_[1];
  pf_init_pose_cov.m[2][2] = init_cov_[2];
  //根据这些参数为粒子滤波器生成sample_count个粒子
  //并且将里面的粒子进行聚类，然后计算这个聚类（也就是单峰）的均值和协方差
  pf_init(pf_, pf_init_pose_mean, pf_init_pose_cov);

  pf_init_ = false;     //有了初始位姿
  resample_count_ = 0;
  memset(&pf_odom_pose_, 0, sizeof(pf_odom_pose_));
}

void
AmclNode::initLaserScan()
{
  scan_error_count_ = 0;
  last_laser_received_ts_ = rclcpp::Time(0);
}

}  // namespace nav2_amcl
