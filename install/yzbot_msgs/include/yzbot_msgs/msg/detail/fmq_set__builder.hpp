// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/FmqSet.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__FMQ_SET__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__FMQ_SET__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/fmq_set__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_FmqSet_switch_status
{
public:
  Init_FmqSet_switch_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yzbot_msgs::msg::FmqSet switch_status(::yzbot_msgs::msg::FmqSet::_switch_status_type arg)
  {
    msg_.switch_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::FmqSet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::FmqSet>()
{
  return yzbot_msgs::msg::builder::Init_FmqSet_switch_status();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__FMQ_SET__BUILDER_HPP_
