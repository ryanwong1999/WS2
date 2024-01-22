// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PscHeadControl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/psc_head_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PscHeadControl_set_pitch
{
public:
  explicit Init_PscHeadControl_set_pitch(::yzbot_msgs::msg::PscHeadControl & msg)
  : msg_(msg)
  {}
  ::yzbot_msgs::msg::PscHeadControl set_pitch(::yzbot_msgs::msg::PscHeadControl::_set_pitch_type arg)
  {
    msg_.set_pitch = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PscHeadControl msg_;
};

class Init_PscHeadControl_set_level
{
public:
  Init_PscHeadControl_set_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PscHeadControl_set_pitch set_level(::yzbot_msgs::msg::PscHeadControl::_set_level_type arg)
  {
    msg_.set_level = std::move(arg);
    return Init_PscHeadControl_set_pitch(msg_);
  }

private:
  ::yzbot_msgs::msg::PscHeadControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PscHeadControl>()
{
  return yzbot_msgs::msg::builder::Init_PscHeadControl_set_level();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__BUILDER_HPP_
