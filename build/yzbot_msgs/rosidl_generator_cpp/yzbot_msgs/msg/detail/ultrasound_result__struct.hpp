// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/UltrasoundResult.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__ULTRASOUND_RESULT__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__ULTRASOUND_RESULT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__UltrasoundResult __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__UltrasoundResult __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UltrasoundResult_
{
  using Type = UltrasoundResult_<ContainerAllocator>;

  explicit UltrasoundResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cs_obs = 0;
      this->fz_obs = 0;
    }
  }

  explicit UltrasoundResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cs_obs = 0;
      this->fz_obs = 0;
    }
  }

  // field types and members
  using _cs_obs_type =
    int8_t;
  _cs_obs_type cs_obs;
  using _fz_obs_type =
    int8_t;
  _fz_obs_type fz_obs;

  // setters for named parameter idiom
  Type & set__cs_obs(
    const int8_t & _arg)
  {
    this->cs_obs = _arg;
    return *this;
  }
  Type & set__fz_obs(
    const int8_t & _arg)
  {
    this->fz_obs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__UltrasoundResult
    std::shared_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__UltrasoundResult
    std::shared_ptr<yzbot_msgs::msg::UltrasoundResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UltrasoundResult_ & other) const
  {
    if (this->cs_obs != other.cs_obs) {
      return false;
    }
    if (this->fz_obs != other.fz_obs) {
      return false;
    }
    return true;
  }
  bool operator!=(const UltrasoundResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UltrasoundResult_

// alias to use template instance with default allocator
using UltrasoundResult =
  yzbot_msgs::msg::UltrasoundResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__ULTRASOUND_RESULT__STRUCT_HPP_
