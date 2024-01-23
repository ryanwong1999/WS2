#include "psc.hpp"

/**
  构造函数初始化
**/
PSC::PSC(RobotSerial *Robotserial_) : Node("psc")
{
    mRobotSerial = Robotserial_;

    obs_pub = this->create_publisher<yzbot_msgs::msg::ObsResult>("obs_result", 10);
    robot_button_pub = this->create_publisher<yzbot_msgs::msg::RobotButton>("robot_button", 10);
    psc_neck_status_pub = this->create_publisher<yzbot_msgs::msg::PscGetNeckStatus>("psc_get_neck_status", 10);
    psc_head_status_pub = this->create_publisher<yzbot_msgs::msg::PscGetHeadStatus>("psc_get_head_status", 10);
    emergency_pub = this->create_publisher<yzbot_msgs::msg::EmergencyButton>("emergency_button", 10);
}

PSC::~PSC() {}

// 查询头部云台状态
int PSC::queryHeadPose(void)
{
    int head_pose;
    head_pose = mRobotSerial->getHeadPose(psc_head_status.level, psc_head_status.pitch, emergency_switch_flag);
    // RCLCPP_INFO(get_logger(), "psc_head_level: %d  psc_head_pitch: %d", psc_head_status.level, psc_head_status.pitch);

    yzbot_msgs::msg::EmergencyButton emergency_msg;
    emergency_msg.emergency_button = emergency_switch_flag;
    emergency_pub->publish(emergency_msg);
    
    yzbot_msgs::msg::PscGetHeadStatus psc_head_msg;
    psc_head_msg.get_level = psc_head_status.level;
    psc_head_msg.get_pitch = psc_head_status.pitch;
    psc_head_status_pub->publish(psc_head_msg);

    return head_pose != 0 ? 0 : 1;
}

// 查询升降杆状态
int PSC::queryNeckPose(void)
{
    int neck_pose;
    neck_pose = mRobotSerial->getNeckPose(psc_neck_status.height, psc_neck_status.limit, psc_neck_status.done, flag_light, flag_bebebe);
    // RCLCPP_INFO(get_logger(), "psc_neck_status---  height: %d  limit: %d  done: %d", psc_neck_status.height, psc_neck_status.limit, psc_neck_status.done);
 
    yzbot_msgs::msg::PscGetNeckStatus psc_neck_msg;
    psc_neck_msg.get_height = psc_neck_status.height;
    psc_neck_msg.get_limit = psc_neck_status.limit;
    psc_neck_msg.get_done = psc_neck_status.done;
    psc_neck_status_pub->publish(psc_neck_msg);

    return neck_pose != 0 ? 0 : 1;
}

// 查询障碍信息
int PSC::queryObsState(void)
{
    int obs_state;
    obs_state = mRobotSerial->getUltrasoundResult(psc_obs_status.cs, psc_obs_status.fz);
    // RCLCPP_INFO(this->get_logger(), "psc_obs_status.cs: %d  psc_obs_status.fz: %d", psc_obs_status.cs, psc_obs_status.fz);
    yzbot_msgs::msg::ObsResult psc_obs_msg;
    psc_obs_msg.cs_obs = psc_obs_status.cs;
    psc_obs_msg.fz_obs = psc_obs_status.fz;
    obs_pub->publish(psc_obs_msg);

    return obs_state != 0 ? 0 : 1;
}

// 查询按钮状态
int PSC::queryRobotButton(void)
{
    int button_state;
    button_state = mRobotSerial->getRobotButton(psc_robot_button.audio_button, psc_robot_button.power_button, psc_robot_button.zs);

    yzbot_msgs::msg::RobotButton robot_button_msg;
    robot_button_msg.button_audio = psc_robot_button.audio_button;
    robot_button_msg.button_power = psc_robot_button.power_button;
    // 接收到关机信号
    if(robot_button_msg.button_power == 1) std::system("shutdown now");
    // robot_button_msg.zs = robot_button.zs;
    robot_button_pub->publish(robot_button_msg);

    return button_state != 0 ? 0 : 1;
}

// 按照高度精确控制升降杆
void PSC::neckControlByHeightCallback(const yzbot_msgs::msg::PscNeckControl::SharedPtr msg)
{
    psc_height_neck_control_flag = 1;  
    psc_goal_height = msg->set_height;
    RCLCPP_INFO(this->get_logger(), "psc_goal_height: %d", psc_goal_height);
}

// 按照角度精确控制头部云台
void PSC::headControlByAngleCallback(const yzbot_msgs::msg::PscHeadControl::SharedPtr msg)
{
    psc_angle_head_control_flag = 1;
    psc_goal_level = msg->set_level;
    psc_goal_pitch = msg->set_pitch;
    RCLCPP_INFO(this->get_logger(), "psc_goal_level: %d  psc_goal_pitch: %d", psc_goal_level, psc_goal_pitch);
}

// 按键控制升降杆
void PSC::neckControlByKeyCallback(const yzbot_msgs::msg::PscKeyNeckControl::SharedPtr msg)
{
    psc_key_neck_control_flag = 1; 
    psc_key_neck_control_direction = msg->psc_neck_direction;
}

// 按键控制头部云台
void PSC::headControlByKeyCallback(const yzbot_msgs::msg::PscKeyHeadControl::SharedPtr msg)
{
    psc_key_head_control_flag = 1; 
    psc_key_head_control_direction = msg->psc_head_direction;
}

// 头部云台偏移量调节
void PSC::setHeadOffsetCallback(const yzbot_msgs::msg::PscHeadOffset::SharedPtr msg)
{
    psc_head_offset_en = msg->offset_set_en;
}