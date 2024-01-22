// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PscGetNeckStatus.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/psc_get_neck_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PscGetNeckStatus_get_done
{
public:
  explicit Init_PscGetNeckStatus_get_done(::yzbot_msgs::msg::PscGetNeckStatus & msg)
  : msg_(msg)
  {}
  ::yzbot_msgs::msg::PscGetNeckStatus get_done(::yzbot_msgs::msg::PscGetNeckStatus::_get_done_type arg)
  {
    msg_.get_done = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PscGetNeckStatus msg_;
};

class Init_PscGetNeckStatus_get_limit
{
public:
  explicit Init_PscGetNeckStatus_get_limit(::yzbot_msgs::msg::PscGetNeckStatus & msg)
  : msg_(msg)
  {}
  Init_PscGetNeckStatus_get_done get_limit(::yzbot_msgs::msg::PscGetNeckStatus::_get_limit_type arg)
  {
    msg_.get_limit = std::move(arg);
    return Init_PscGetNeckStatus_get_done(msg_);
  }

private:
  ::yzbot_msgs::msg::PscGetNeckStatus msg_;
};

class Init_PscGetNeckStatus_get_height
{
public:
  Init_PscGetNeckStatus_get_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PscGetNeckStatus_get_limit get_height(::yzbot_msgs::msg::PscGetNeckStatus::_get_height_type arg)
  {
    msg_.get_height = std::move(arg);
    return Init_PscGetNeckStatus_get_limit(msg_);
  }

private:
  ::yzbot_msgs::msg::PscGetNeckStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PscGetNeckStatus>()
{
  return yzbot_msgs::msg::builder::Init_PscGetNeckStatus_get_height();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__BUILDER_HPP_
