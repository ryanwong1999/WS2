// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/PmsStatus.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PMS_STATUS__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PMS_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__PmsStatus __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__PmsStatus __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PmsStatus_
{
  using Type = PmsStatus_<ContainerAllocator>;

  explicit PmsStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pms_charging_flag = 0l;
      this->pms_battery_level = 0l;
    }
  }

  explicit PmsStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pms_charging_flag = 0l;
      this->pms_battery_level = 0l;
    }
  }

  // field types and members
  using _pms_charging_flag_type =
    int32_t;
  _pms_charging_flag_type pms_charging_flag;
  using _pms_battery_level_type =
    int32_t;
  _pms_battery_level_type pms_battery_level;

  // setters for named parameter idiom
  Type & set__pms_charging_flag(
    const int32_t & _arg)
  {
    this->pms_charging_flag = _arg;
    return *this;
  }
  Type & set__pms_battery_level(
    const int32_t & _arg)
  {
    this->pms_battery_level = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::PmsStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::PmsStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PmsStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PmsStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__PmsStatus
    std::shared_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__PmsStatus
    std::shared_ptr<yzbot_msgs::msg::PmsStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PmsStatus_ & other) const
  {
    if (this->pms_charging_flag != other.pms_charging_flag) {
      return false;
    }
    if (this->pms_battery_level != other.pms_battery_level) {
      return false;
    }
    return true;
  }
  bool operator!=(const PmsStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PmsStatus_

// alias to use template instance with default allocator
using PmsStatus =
  yzbot_msgs::msg::PmsStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PMS_STATUS__STRUCT_HPP_
