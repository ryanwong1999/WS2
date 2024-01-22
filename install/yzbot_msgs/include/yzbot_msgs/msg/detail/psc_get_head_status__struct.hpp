// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/PscGetHeadStatus.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_GET_HEAD_STATUS__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_GET_HEAD_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__PscGetHeadStatus __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__PscGetHeadStatus __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PscGetHeadStatus_
{
  using Type = PscGetHeadStatus_<ContainerAllocator>;

  explicit PscGetHeadStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->get_level = 0l;
      this->get_pitch = 0l;
    }
  }

  explicit PscGetHeadStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->get_level = 0l;
      this->get_pitch = 0l;
    }
  }

  // field types and members
  using _get_level_type =
    int32_t;
  _get_level_type get_level;
  using _get_pitch_type =
    int32_t;
  _get_pitch_type get_pitch;

  // setters for named parameter idiom
  Type & set__get_level(
    const int32_t & _arg)
  {
    this->get_level = _arg;
    return *this;
  }
  Type & set__get_pitch(
    const int32_t & _arg)
  {
    this->get_pitch = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__PscGetHeadStatus
    std::shared_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__PscGetHeadStatus
    std::shared_ptr<yzbot_msgs::msg::PscGetHeadStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PscGetHeadStatus_ & other) const
  {
    if (this->get_level != other.get_level) {
      return false;
    }
    if (this->get_pitch != other.get_pitch) {
      return false;
    }
    return true;
  }
  bool operator!=(const PscGetHeadStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PscGetHeadStatus_

// alias to use template instance with default allocator
using PscGetHeadStatus =
  yzbot_msgs::msg::PscGetHeadStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_GET_HEAD_STATUS__STRUCT_HPP_
