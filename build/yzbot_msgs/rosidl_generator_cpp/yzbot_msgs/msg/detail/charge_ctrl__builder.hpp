// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/ChargeCtrl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__CHARGE_CTRL__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__CHARGE_CTRL__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/charge_ctrl__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_ChargeCtrl_auto_charge_flag
{
public:
  Init_ChargeCtrl_auto_charge_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yzbot_msgs::msg::ChargeCtrl auto_charge_flag(::yzbot_msgs::msg::ChargeCtrl::_auto_charge_flag_type arg)
  {
    msg_.auto_charge_flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::ChargeCtrl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::ChargeCtrl>()
{
  return yzbot_msgs::msg::builder::Init_ChargeCtrl_auto_charge_flag();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__CHARGE_CTRL__BUILDER_HPP_
