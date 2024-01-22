// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/PscHeadControl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__PscHeadControl __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__PscHeadControl __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PscHeadControl_
{
  using Type = PscHeadControl_<ContainerAllocator>;

  explicit PscHeadControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_level = 0l;
      this->set_pitch = 0l;
    }
  }

  explicit PscHeadControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_level = 0l;
      this->set_pitch = 0l;
    }
  }

  // field types and members
  using _set_level_type =
    int32_t;
  _set_level_type set_level;
  using _set_pitch_type =
    int32_t;
  _set_pitch_type set_pitch;

  // setters for named parameter idiom
  Type & set__set_level(
    const int32_t & _arg)
  {
    this->set_level = _arg;
    return *this;
  }
  Type & set__set_pitch(
    const int32_t & _arg)
  {
    this->set_pitch = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::PscHeadControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::PscHeadControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscHeadControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscHeadControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__PscHeadControl
    std::shared_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__PscHeadControl
    std::shared_ptr<yzbot_msgs::msg::PscHeadControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PscHeadControl_ & other) const
  {
    if (this->set_level != other.set_level) {
      return false;
    }
    if (this->set_pitch != other.set_pitch) {
      return false;
    }
    return true;
  }
  bool operator!=(const PscHeadControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PscHeadControl_

// alias to use template instance with default allocator
using PscHeadControl =
  yzbot_msgs::msg::PscHeadControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__STRUCT_HPP_
