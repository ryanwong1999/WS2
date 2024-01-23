#ifndef __STM32_CONNECT_HPP__
#define __STM32_CONNECT_HPP__

#include "rclcpp/rclcpp.hpp"
#include "robotserial.hpp"
#include "plc.hpp"
#include "pms.hpp"
#include "psc.hpp"
#include "serial/serial.h"
#include <string>
#include <iostream>

class Stm32_Connect : public rclcpp::Node
{
public:
    Stm32_Connect();
    ~Stm32_Connect();
    
    std::shared_ptr<serial::Serial> serial_;
    std::shared_ptr<RobotSerial> RobotSerial_;
    std::shared_ptr<PLC> PLC_;
    std::shared_ptr<PMS> PMS_;
    std::shared_ptr<PSC> PSC_;

    bool initSerial();

private:
    void timerCallback();

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub;
    rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr amcl_pose_sub;
    rclcpp::Subscription<yzbot_msgs::msg::FmqSet>::SharedPtr fmq_sub;
    rclcpp::Subscription<yzbot_msgs::msg::ChargeCtrl>::SharedPtr charge_sub;
    rclcpp::Subscription<yzbot_msgs::msg::PscNeckControl>::SharedPtr neck_control_sub;
    rclcpp::Subscription<yzbot_msgs::msg::PscHeadControl>::SharedPtr head_control_sub;
    rclcpp::Subscription<yzbot_msgs::msg::PscKeyNeckControl>::SharedPtr key_neck_control_sub;
    rclcpp::Subscription<yzbot_msgs::msg::PscKeyHeadControl>::SharedPtr key_head_control_sub;
    rclcpp::Subscription<yzbot_msgs::msg::PscHeadOffset>::SharedPtr head_offset_sub;


    rclcpp::TimerBase::SharedPtr timer_;
};

#endif