// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/robot_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotPose_robot_state
{
public:
  explicit Init_RobotPose_robot_state(::yzbot_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  ::yzbot_msgs::msg::RobotPose robot_state(::yzbot_msgs::msg::RobotPose::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_yaw
{
public:
  explicit Init_RobotPose_yaw(::yzbot_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  Init_RobotPose_robot_state yaw(::yzbot_msgs::msg::RobotPose::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_RobotPose_robot_state(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_robot_yaw
{
public:
  explicit Init_RobotPose_robot_yaw(::yzbot_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  Init_RobotPose_yaw robot_yaw(::yzbot_msgs::msg::RobotPose::_robot_yaw_type arg)
  {
    msg_.robot_yaw = std::move(arg);
    return Init_RobotPose_yaw(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_robot_y
{
public:
  explicit Init_RobotPose_robot_y(::yzbot_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  Init_RobotPose_robot_yaw robot_y(::yzbot_msgs::msg::RobotPose::_robot_y_type arg)
  {
    msg_.robot_y = std::move(arg);
    return Init_RobotPose_robot_yaw(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_robot_x
{
public:
  Init_RobotPose_robot_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotPose_robot_y robot_x(::yzbot_msgs::msg::RobotPose::_robot_x_type arg)
  {
    msg_.robot_x = std::move(arg);
    return Init_RobotPose_robot_y(msg_);
  }

private:
  ::yzbot_msgs::msg::RobotPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::RobotPose>()
{
  return yzbot_msgs::msg::builder::Init_RobotPose_robot_x();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
