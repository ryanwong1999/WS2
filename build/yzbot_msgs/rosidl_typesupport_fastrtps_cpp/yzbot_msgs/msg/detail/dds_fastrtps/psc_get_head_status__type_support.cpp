// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from yzbot_msgs:msg/PscGetHeadStatus.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/psc_get_head_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "yzbot_msgs/msg/detail/psc_get_head_status__struct.hpp"

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
  const yzbot_msgs::msg::PscGetHeadStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: get_level
  cdr << ros_message.get_level;
  // Member: get_pitch
  cdr << ros_message.get_pitch;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yzbot_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  yzbot_msgs::msg::PscGetHeadStatus & ros_message)
{
  // Member: get_level
  cdr >> ros_message.get_level;

  // Member: get_pitch
  cdr >> ros_message.get_pitch;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yzbot_msgs
get_serialized_size(
  const yzbot_msgs::msg::PscGetHeadStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: get_level
  {
    size_t item_size = sizeof(ros_message.get_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: get_pitch
  {
    size_t item_size = sizeof(ros_message.get_pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yzbot_msgs
max_serialized_size_PscGetHeadStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: get_level
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: get_pitch
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _PscGetHeadStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const yzbot_msgs::msg::PscGetHeadStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PscGetHeadStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<yzbot_msgs::msg::PscGetHeadStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PscGetHeadStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const yzbot_msgs::msg::PscGetHeadStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PscGetHeadStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PscGetHeadStatus(full_bounded, 0);
}

static message_type_support_callbacks_t _PscGetHeadStatus__callbacks = {
  "yzbot_msgs::msg",
  "PscGetHeadStatus",
  _PscGetHeadStatus__cdr_serialize,
  _PscGetHeadStatus__cdr_deserialize,
  _PscGetHeadStatus__get_serialized_size,
  _PscGetHeadStatus__max_serialized_size
};

static rosidl_message_type_support_t _PscGetHeadStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PscGetHeadStatus__callbacks,
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
get_message_type_support_handle<yzbot_msgs::msg::PscGetHeadStatus>()
{
  return &yzbot_msgs::msg::typesupport_fastrtps_cpp::_PscGetHeadStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, yzbot_msgs, msg, PscGetHeadStatus)() {
  return &yzbot_msgs::msg::typesupport_fastrtps_cpp::_PscGetHeadStatus__handle;
}

#ifdef __cplusplus
}
#endif
