#ifndef PLC_HPP_
#define PLC_HPP_

#include "rclcpp/rclcpp.hpp"
#include "robotserial.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
// #include "geometry_msgs/msg/twist.hpp"
#include "yzbot_msgs/msg/robot_pose.hpp"
#include "yzbot_msgs/msg/fmq_set.hpp"
#include <cmath>
#include <chrono>

#define Sign(y) (y>=0?1:-1)
#define PRE_RATE        0.0174532925
#define PI              3.1415926535
#define PULSE_CYCLE     5600    // 1400*4
#define WHEEL_DIAMETER  0.169
#define WHEEL_DISTANCE  0.381

// 定义一个机器人位子结构体
struct Robot_pose
{
    float robot_x;      // X坐标
    float robot_y;      // Y坐标
    float robot_yaw;    // 角度
};

class PLC : public rclcpp::Node
{
public:
    PLC(RobotSerial *Robotserial_);
    ~PLC();

    float th_total_h;
    // 机器人的当前坐标  估计
    float g_x, g_y;
    // 这个是 cmd_vel 中的速度 
    float g_vx, g_vy, g_vth;
    double mRobotPose_x, mRobotPose_y, mRobotPose_yaw;
    double mD;
    float pulse_sec = 0;        // 每个脉冲对应距离
    float wheel_diameter = 0;   // 轮子直径
    float wheel_distance = 0;   // 轮距  
    int fmq_status_flag = 0;

    Robot_pose my_robot_pose; 
    rclcpp::Time current_time = now();
    rclcpp::Time last_time = now();
    rclcpp::Time robot_pose_lasttime = now();
    
    
    // 发布里程计信息
    int pub_odom(short int vx, short int vy, short int t1, short int  t2, float angle_v, float angle, float n_vx, float n_vth);
    void pub_robot_pose(int left_t, int right_t, double angle_t, double angle_l);
    void plc_timer_deal_odom();
    void get_auto_speed();
    
private:
    RobotSerial *mRobotSerial;

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub;
    rclcpp::Publisher<yzbot_msgs::msg::RobotPose>::SharedPtr robot_pose_pub;
    
    rclcpp::Subscription<yzbot_msgs::msg::FmqSet>::SharedPtr fmq_sub;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub;
    rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr amcl_pose_sub;

    void get_fmq_callback(const yzbot_msgs::msg::FmqSet::SharedPtr msg);
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr cmd_vel);
    void amcl_pose_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr amcl_pose);

};
#endif