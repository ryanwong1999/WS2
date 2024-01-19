// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/FmqSet.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__FMQ_SET__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__FMQ_SET__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__FmqSet __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__FmqSet __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FmqSet_
{
  using Type = FmqSet_<ContainerAllocator>;

  explicit FmqSet_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->switch_status = 0;
    }
  }

  explicit FmqSet_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->switch_status = 0;
    }
  }

  // field types and members
  using _switch_status_type =
    int8_t;
  _switch_status_type switch_status;

  // setters for named parameter idiom
  Type & set__switch_status(
    const int8_t & _arg)
  {
    this->switch_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::FmqSet_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::FmqSet_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::FmqSet_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::FmqSet_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__FmqSet
    std::shared_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__FmqSet
    std::shared_ptr<yzbot_msgs::msg::FmqSet_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FmqSet_ & other) const
  {
    if (this->switch_status != other.switch_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const FmqSet_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FmqSet_

// alias to use template instance with default allocator
using FmqSet =
  yzbot_msgs::msg::FmqSet_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__FMQ_SET__STRUCT_HPP_
