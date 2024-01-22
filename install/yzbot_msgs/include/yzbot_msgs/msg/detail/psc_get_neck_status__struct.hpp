// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/PscGetNeckStatus.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__PscGetNeckStatus __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__PscGetNeckStatus __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PscGetNeckStatus_
{
  using Type = PscGetNeckStatus_<ContainerAllocator>;

  explicit PscGetNeckStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->get_height = 0l;
      this->get_limit = 0l;
      this->get_done = 0l;
    }
  }

  explicit PscGetNeckStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->get_height = 0l;
      this->get_limit = 0l;
      this->get_done = 0l;
    }
  }

  // field types and members
  using _get_height_type =
    int32_t;
  _get_height_type get_height;
  using _get_limit_type =
    int32_t;
  _get_limit_type get_limit;
  using _get_done_type =
    int32_t;
  _get_done_type get_done;

  // setters for named parameter idiom
  Type & set__get_height(
    const int32_t & _arg)
  {
    this->get_height = _arg;
    return *this;
  }
  Type & set__get_limit(
    const int32_t & _arg)
  {
    this->get_limit = _arg;
    return *this;
  }
  Type & set__get_done(
    const int32_t & _arg)
  {
    this->get_done = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__PscGetNeckStatus
    std::shared_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__PscGetNeckStatus
    std::shared_ptr<yzbot_msgs::msg::PscGetNeckStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PscGetNeckStatus_ & other) const
  {
    if (this->get_height != other.get_height) {
      return false;
    }
    if (this->get_limit != other.get_limit) {
      return false;
    }
    if (this->get_done != other.get_done) {
      return false;
    }
    return true;
  }
  bool operator!=(const PscGetNeckStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PscGetNeckStatus_

// alias to use template instance with default allocator
using PscGetNeckStatus =
  yzbot_msgs::msg::PscGetNeckStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__STRUCT_HPP_
