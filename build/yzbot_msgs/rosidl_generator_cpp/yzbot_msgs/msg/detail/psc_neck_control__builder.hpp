// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PscNeckControl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_NECK_CONTROL__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_NECK_CONTROL__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/psc_neck_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PscNeckControl_set_height
{
public:
  Init_PscNeckControl_set_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yzbot_msgs::msg::PscNeckControl set_height(::yzbot_msgs::msg::PscNeckControl::_set_height_type arg)
  {
    msg_.set_height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PscNeckControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PscNeckControl>()
{
  return yzbot_msgs::msg::builder::Init_PscNeckControl_set_height();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_NECK_CONTROL__BUILDER_HPP_
