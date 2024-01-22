// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PscGetHeadStatus.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_GET_HEAD_STATUS__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_GET_HEAD_STATUS__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/psc_get_head_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PscGetHeadStatus_get_pitch
{
public:
  explicit Init_PscGetHeadStatus_get_pitch(::yzbot_msgs::msg::PscGetHeadStatus & msg)
  : msg_(msg)
  {}
  ::yzbot_msgs::msg::PscGetHeadStatus get_pitch(::yzbot_msgs::msg::PscGetHeadStatus::_get_pitch_type arg)
  {
    msg_.get_pitch = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PscGetHeadStatus msg_;
};

class Init_PscGetHeadStatus_get_level
{
public:
  Init_PscGetHeadStatus_get_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PscGetHeadStatus_get_pitch get_level(::yzbot_msgs::msg::PscGetHeadStatus::_get_level_type arg)
  {
    msg_.get_level = std::move(arg);
    return Init_PscGetHeadStatus_get_pitch(msg_);
  }

private:
  ::yzbot_msgs::msg::PscGetHeadStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PscGetHeadStatus>()
{
  return yzbot_msgs::msg::builder::Init_PscGetHeadStatus_get_level();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_GET_HEAD_STATUS__BUILDER_HPP_
