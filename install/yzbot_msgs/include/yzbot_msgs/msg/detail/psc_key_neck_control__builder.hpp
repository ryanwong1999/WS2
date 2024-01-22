// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PscKeyNeckControl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_KEY_NECK_CONTROL__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_KEY_NECK_CONTROL__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/psc_key_neck_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PscKeyNeckControl_psc_neck_direction
{
public:
  Init_PscKeyNeckControl_psc_neck_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yzbot_msgs::msg::PscKeyNeckControl psc_neck_direction(::yzbot_msgs::msg::PscKeyNeckControl::_psc_neck_direction_type arg)
  {
    msg_.psc_neck_direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PscKeyNeckControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PscKeyNeckControl>()
{
  return yzbot_msgs::msg::builder::Init_PscKeyNeckControl_psc_neck_direction();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_KEY_NECK_CONTROL__BUILDER_HPP_
