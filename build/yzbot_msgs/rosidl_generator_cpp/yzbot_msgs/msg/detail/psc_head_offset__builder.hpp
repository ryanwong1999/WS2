// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PscHeadOffset.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/psc_head_offset__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PscHeadOffset_offset_set_en
{
public:
  Init_PscHeadOffset_offset_set_en()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yzbot_msgs::msg::PscHeadOffset offset_set_en(::yzbot_msgs::msg::PscHeadOffset::_offset_set_en_type arg)
  {
    msg_.offset_set_en = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PscHeadOffset msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PscHeadOffset>()
{
  return yzbot_msgs::msg::builder::Init_PscHeadOffset_offset_set_en();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__BUILDER_HPP_
