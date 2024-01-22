// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/RobotButton.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__RobotButton __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__RobotButton __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotButton_
{
  using Type = RobotButton_<ContainerAllocator>;

  explicit RobotButton_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->button_audio = 0l;
      this->button_power = 0l;
      this->zs = 0l;
    }
  }

  explicit RobotButton_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->button_audio = 0l;
      this->button_power = 0l;
      this->zs = 0l;
    }
  }

  // field types and members
  using _button_audio_type =
    int32_t;
  _button_audio_type button_audio;
  using _button_power_type =
    int32_t;
  _button_power_type button_power;
  using _zs_type =
    int32_t;
  _zs_type zs;

  // setters for named parameter idiom
  Type & set__button_audio(
    const int32_t & _arg)
  {
    this->button_audio = _arg;
    return *this;
  }
  Type & set__button_power(
    const int32_t & _arg)
  {
    this->button_power = _arg;
    return *this;
  }
  Type & set__zs(
    const int32_t & _arg)
  {
    this->zs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::RobotButton_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::RobotButton_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::RobotButton_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::RobotButton_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__RobotButton
    std::shared_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__RobotButton
    std::shared_ptr<yzbot_msgs::msg::RobotButton_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotButton_ & other) const
  {
    if (this->button_audio != other.button_audio) {
      return false;
    }
    if (this->button_power != other.button_power) {
      return false;
    }
    if (this->zs != other.zs) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotButton_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotButton_

// alias to use template instance with default allocator
using RobotButton =
  yzbot_msgs::msg::RobotButton_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__STRUCT_HPP_
