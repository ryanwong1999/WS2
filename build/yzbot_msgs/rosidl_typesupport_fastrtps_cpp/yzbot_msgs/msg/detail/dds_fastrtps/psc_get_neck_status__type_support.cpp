// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from yzbot_msgs:msg/PscGetNeckStatus.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/psc_get_neck_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "yzbot_msgs/msg/detail/psc_get_neck_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace yzbot_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yzbot_msgs
cdr_serialize(
  const yzbot_msgs::msg::PscGetNeckStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: get_height
  cdr << ros_message.get_height;
  // Member: get_limit
  cdr << ros_message.get_limit;
  // Member: get_done
  cdr << ros_message.get_done;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yzbot_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  yzbot_msgs::msg::PscGetNeckStatus & ros_message)
{
  // Member: get_height
  cdr >> ros_message.get_height;

  // Member: get_limit
  cdr >> ros_message.get_limit;

  // Member: get_done
  cdr >> ros_message.get_done;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yzbot_msgs
get_serialized_size(
  const yzbot_msgs::msg::PscGetNeckStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: get_height
  {
    size_t item_size = sizeof(ros_message.get_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: get_limit
  {
    size_t item_size = sizeof(ros_message.get_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: get_done
  {
    size_t item_size = sizeof(ros_message.get_done);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yzbot_msgs
max_serialized_size_PscGetNeckStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: get_height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: get_limit
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: get_done
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _PscGetNeckStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const yzbot_msgs::msg::PscGetNeckStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PscGetNeckStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<yzbot_msgs::msg::PscGetNeckStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PscGetNeckStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const yzbot_msgs::msg::PscGetNeckStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PscGetNeckStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PscGetNeckStatus(full_bounded, 0);
}

static message_type_support_callbacks_t _PscGetNeckStatus__callbacks = {
  "yzbot_msgs::msg",
  "PscGetNeckStatus",
  _PscGetNeckStatus__cdr_serialize,
  _PscGetNeckStatus__cdr_deserialize,
  _PscGetNeckStatus__get_serialized_size,
  _PscGetNeckStatus__max_serialized_size
};

static rosidl_message_type_support_t _PscGetNeckStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PscGetNeckStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace yzbot_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_yzbot_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<yzbot_msgs::msg::PscGetNeckStatus>()
{
  return &yzbot_msgs::msg::typesupport_fastrtps_cpp::_PscGetNeckStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, yzbot_msgs, msg, PscGetNeckStatus)() {
  return &yzbot_msgs::msg::typesupport_fastrtps_cpp::_PscGetNeckStatus__handle;
}

#ifdef __cplusplus
}
#endif
