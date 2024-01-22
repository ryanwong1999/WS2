// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yzbot_msgs:msg/PscHeadOffset.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__STRUCT_HPP_
#define YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__yzbot_msgs__msg__PscHeadOffset __attribute__((deprecated))
#else
# define DEPRECATED__yzbot_msgs__msg__PscHeadOffset __declspec(deprecated)
#endif

namespace yzbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PscHeadOffset_
{
  using Type = PscHeadOffset_<ContainerAllocator>;

  explicit PscHeadOffset_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offset_set_en = 0;
    }
  }

  explicit PscHeadOffset_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offset_set_en = 0;
    }
  }

  // field types and members
  using _offset_set_en_type =
    int8_t;
  _offset_set_en_type offset_set_en;

  // setters for named parameter idiom
  Type & set__offset_set_en(
    const int8_t & _arg)
  {
    this->offset_set_en = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator> *;
  using ConstRawPtr =
    const yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yzbot_msgs__msg__PscHeadOffset
    std::shared_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yzbot_msgs__msg__PscHeadOffset
    std::shared_ptr<yzbot_msgs::msg::PscHeadOffset_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PscHeadOffset_ & other) const
  {
    if (this->offset_set_en != other.offset_set_en) {
      return false;
    }
    return true;
  }
  bool operator!=(const PscHeadOffset_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PscHeadOffset_

// alias to use template instance with default allocator
using PscHeadOffset =
  yzbot_msgs::msg::PscHeadOffset_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yzbot_msgs

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__STRUCT_HPP_
