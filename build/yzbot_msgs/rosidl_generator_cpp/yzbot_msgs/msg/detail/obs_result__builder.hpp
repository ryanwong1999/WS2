// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yzbot_msgs:msg/ObsResult.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__OBS_RESULT__BUILDER_HPP_
#define YZBOT_MSGS__MSG__DETAIL__OBS_RESULT__BUILDER_HPP_

#include "yzbot_msgs/msg/detail/obs_result__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace yzbot_msgs
{

namespace msg
{

namespace builder
{

class Init_ObsResult_fz_obs
{
public:
  explicit Init_ObsResult_fz_obs(::yzbot_msgs::msg::ObsResult & msg)
  : msg_(msg)
  {}
  ::yzbot_msgs::msg::ObsResult fz_obs(::yzbot_msgs::msg::ObsResult::_fz_obs_type arg)
  {
    msg_.fz_obs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yzbot_msgs::msg::ObsResult msg_;
};

class Init_ObsResult_cs_obs
{
public:
  Init_ObsResult_cs_obs()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObsResult_fz_obs cs_obs(::yzbot_msgs::msg::ObsResult::_cs_obs_type arg)
  {
    msg_.cs_obs = std::move(arg);
    return Init_ObsResult_fz_obs(msg_);
  }

private:
  ::yzbot_msgs::msg::ObsResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yzbot_msgs::msg::ObsResult>()
{
  return yzbot_msgs::msg::builder::Init_ObsResult_cs_obs();
}

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__OBS_RESULT__BUILDER_HPP_
