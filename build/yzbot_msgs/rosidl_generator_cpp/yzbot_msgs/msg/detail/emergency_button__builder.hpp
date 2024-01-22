// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/EmergencyButton.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/emergency_button__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_EmergencyButton_emergency_button
{
public:
  Init_EmergencyButton_emergency_button()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yzbot_msgs::msg::EmergencyButton emergency_button(::yzbot_msgs::msg::EmergencyButton::_emergency_button_type arg)
  {
    msg_.emergency_button = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::EmergencyButton msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::EmergencyButton>()
{
  return yzbot_msgs::msg::builder::Init_EmergencyButton_emergency_button();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__BUILDER_HPP_
