// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/RobotButton.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/robot_button__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotButton_zs
{
public:
  explicit Init_RobotButton_zs(::yzbot_msgs::msg::RobotButton & msg)
  : msg_(msg)
  {}
  ::yzbot_msgs::msg::RobotButton zs(::yzbot_msgs::msg::RobotButton::_zs_type arg)
  {
    msg_.zs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotButton msg_;
};

class Init_RobotButton_button_power
{
public:
  explicit Init_RobotButton_button_power(::yzbot_msgs::msg::RobotButton & msg)
  : msg_(msg)
  {}
  Init_RobotButton_zs button_power(::yzbot_msgs::msg::RobotButton::_button_power_type arg)
  {
    msg_.button_power = std::move(arg);
    return Init_RobotButton_zs(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotButton msg_;
};

class Init_RobotButton_button_audio
{
public:
  Init_RobotButton_button_audio()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotButton_button_power button_audio(::yzbot_msgs::msg::RobotButton::_button_audio_type arg)
  {
    msg_.button_audio = std::move(arg);
    return Init_RobotButton_button_power(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotButton msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::RobotButton>()
{
  return yzbot_msgs::msg::builder::Init_RobotButton_button_audio();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__BUILDER_HPP_
