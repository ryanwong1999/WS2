// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/PmsStatus.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PMS_STATUS__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PMS_STATUS__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/pms_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_PmsStatus_pms_battery_level
{
public:
  explicit Init_PmsStatus_pms_battery_level(::yzbot_msgs::msg::PmsStatus & msg)
  : msg_(msg)
  {}
  ::yzbot_msgs::msg::PmsStatus pms_battery_level(::yzbot_msgs::msg::PmsStatus::_pms_battery_level_type arg)
  {
    msg_.pms_battery_level = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::PmsStatus msg_;
};

class Init_PmsStatus_pms_charging_flag
{
public:
  Init_PmsStatus_pms_charging_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PmsStatus_pms_battery_level pms_charging_flag(::yzbot_msgs::msg::PmsStatus::_pms_charging_flag_type arg)
  {
    msg_.pms_charging_flag = std::move(arg);
    return Init_PmsStatus_pms_battery_level(msg_);
  }

private:
  ::yzbot_msgs::msg::PmsStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::PmsStatus>()
{
  return yzbot_msgs::msg::builder::Init_PmsStatus_pms_charging_flag();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PMS_STATUS__BUILDER_HPP_
