// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PscKeyHeadControl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_KEY_HEAD_CONTROL__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_KEY_HEAD_CONTROL__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/psc_key_head_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PscKeyHeadControl_psc_head_direction
{
public:
  Init_PscKeyHeadControl_psc_head_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yzbot_msgs::msg::PscKeyHeadControl psc_head_direction(::yzbot_msgs::msg::PscKeyHeadControl::_psc_head_direction_type arg)
  {
    msg_.psc_head_direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PscKeyHeadControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PscKeyHeadControl>()
{
  return yzbot_msgs::msg::builder::Init_PscKeyHeadControl_psc_head_direction();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_KEY_HEAD_CONTROL__BUILDER_HPP_
