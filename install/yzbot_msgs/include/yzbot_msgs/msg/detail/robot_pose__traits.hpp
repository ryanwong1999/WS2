// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yzbot_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__TRAITS_HPP_
#define YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__TRAITS_HPP_

#include "yzbot_msgs/msg/detail/robot_pose__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<yzbot_msgs::msg::RobotPose>()
{
  return "yzbot_msgs::msg::RobotPose";
}

template<>
inline const char * name<yzbot_msgs::msg::RobotPose>()
{
  return "yzbot_msgs/msg/RobotPose";
}

template<>
struct has_fixed_size<yzbot_msgs::msg::RobotPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<yzbot_msgs::msg::RobotPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<yzbot_msgs::msg::RobotPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__TRAITS_HPP_
