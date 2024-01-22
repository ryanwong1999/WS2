// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/EmergencyButton.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__EmergencyButton __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__EmergencyButton __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EmergencyButton_
{
  using Type = EmergencyButton_<ContainerAllocator>;

  explicit EmergencyButton_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->emergency_button = 0l;
    }
  }

  explicit EmergencyButton_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->emergency_button = 0l;
    }
  }

  // field types and members
  using _emergency_button_type =
    int32_t;
  _emergency_button_type emergency_button;

  // setters for named parameter idiom
  Type & set__emergency_button(
    const int32_t & _arg)
  {
    this->emergency_button = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::EmergencyButton_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::EmergencyButton_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::EmergencyButton_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::EmergencyButton_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__EmergencyButton
    std::shared_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__EmergencyButton
    std::shared_ptr<yzbot_msgs::msg::EmergencyButton_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EmergencyButton_ & other) const
  {
    if (this->emergency_button != other.emergency_button) {
      return false;
    }
    return true;
  }
  bool operator!=(const EmergencyButton_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EmergencyButton_

// alias to use template instance with default allocator
using EmergencyButton =
  yzbot_msgs::msg::EmergencyButton_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__STRUCT_HPP_
