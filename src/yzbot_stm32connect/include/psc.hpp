#ifndef PSC_HPP_
#define PSC_HPP_

#include "rclcpp/rclcpp.hpp"
#include "robotserial.hpp"
#include "yzbot_msgs/msg/obs_result.hpp"
#include "yzbot_msgs/msg/robot_button.hpp"
#include "yzbot_msgs/msg/emergency_button.hpp"
#include "yzbot_msgs/msg/psc_head_offset.hpp"
#include "yzbot_msgs/msg/psc_get_head_status.hpp"
#include "yzbot_msgs/msg/psc_get_neck_status.hpp"
#include "yzbot_msgs/msg/psc_head_control.hpp"
#include "yzbot_msgs/msg/psc_neck_control.hpp"
#include "yzbot_msgs/msg/psc_key_head_control.hpp"
#include "yzbot_msgs/msg/psc_key_neck_control.hpp"
#include <cstdlib>  // 对于 system 调用

// 超声防撞条的状态
struct obs_status
{
  int cs;
  int fz;
};

// 按钮状态 和 噪声分贝值
struct robot_button
{
  int audio_button;
  int power_button;
  int zs;
};

// psc 的状态
struct head_status
{
  int level;
  int pitch;
};

struct neck_status
{
  int height;
  int limit;
  int done;
};

// 环境数据
struct envir_status
{
  float temp;
  float hum;
  float Co2;
  float Voc;
  float Pm25;
  float Pm10;
  float Pm1_0;
  float stata;
};

class PSC : public rclcpp::Node
{
public:
  PSC(RobotSerial *Robotserial_);
  ~PSC();

  head_status psc_head_status;    // 这个是头部云台状态的结构体  
  neck_status psc_neck_status;    // 这个是升降杆状态结构体
  envir_status psc_envir_status;  // 环境数据结构体
  obs_status psc_obs_status;      // 障碍信息数据结构体
  robot_button psc_robot_button;  // 按钮状态和噪声分贝值结构体

  int psc_goal_level;
  int psc_goal_pitch;
  int psc_goal_height;
  int emergency_switch_flag;      // 急停开关的标记
  int flag_light, flag_bebebe;    // 大灯、蜂鸣器
  int psc_height_neck_control_flag = 0;
  int psc_angle_head_control_flag = 0;
  int psc_key_neck_control_flag = 0;
  int psc_key_head_control_flag = 0;
  int psc_key_neck_control_direction = 0;
  int psc_key_head_control_direction = 0;
  int psc_head_offset_en = 0;
  
  int queryHeadPose(void);
  int queryNeckPose(void);
  int queryObsState(void); 
  int queryRobotButton(void);
  void headControlByAngleCallback(const yzbot_msgs::msg::PscHeadControl::SharedPtr msg);
  void neckControlByHeightCallback(const yzbot_msgs::msg::PscNeckControl::SharedPtr msg);
  void neckControlByKeyCallback(const yzbot_msgs::msg::PscKeyNeckControl::SharedPtr msg);
  void headControlByKeyCallback(const yzbot_msgs::msg::PscKeyHeadControl::SharedPtr msg);
  void setHeadOffsetCallback(const yzbot_msgs::msg::PscHeadOffset::SharedPtr msg);

private:
  RobotSerial *mRobotSerial;
  
  rclcpp::Publisher<yzbot_msgs::msg::ObsResult>::SharedPtr obs_pub;
  rclcpp::Publisher<yzbot_msgs::msg::RobotButton>::SharedPtr robot_button_pub;
  rclcpp::Publisher<yzbot_msgs::msg::PscGetNeckStatus>::SharedPtr psc_neck_status_pub;
  rclcpp::Publisher<yzbot_msgs::msg::PscGetHeadStatus>::SharedPtr psc_head_status_pub;
  rclcpp::Publisher<yzbot_msgs::msg::EmergencyButton>::SharedPtr emergency_pub;
};

#endif