// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from yzbot_msgs:msg/PscKeyHeadControl.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/psc_key_head_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "yzbot_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yzbot_msgs/msg/detail/psc_key_head_control__struct.h"
#include "yzbot_msgs/msg/detail/psc_key_head_control__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PscKeyHeadControl__ros_msg_type = yzbot_msgs__msg__PscKeyHeadControl;

static bool _PscKeyHeadControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PscKeyHeadControl__ros_msg_type * ros_message = static_cast<const _PscKeyHeadControl__ros_msg_type *>(untyped_ros_message);
  // Field name: psc_head_direction
  {
    cdr << ros_message->psc_head_direction;
  }

  return true;
}

static bool _PscKeyHeadControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PscKeyHeadControl__ros_msg_type * ros_message = static_cast<_PscKeyHeadControl__ros_msg_type *>(untyped_ros_message);
  // Field name: psc_head_direction
  {
    cdr >> ros_message->psc_head_direction;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yzbot_msgs
size_t get_serialized_size_yzbot_msgs__msg__PscKeyHeadControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PscKeyHeadControl__ros_msg_type * ros_message = static_cast<const _PscKeyHeadControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name psc_head_direction
  {
    size_t item_size = sizeof(ros_message->psc_head_direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PscKeyHeadControl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yzbot_msgs__msg__PscKeyHeadControl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yzbot_msgs
size_t max_serialized_size_yzbot_msgs__msg__PscKeyHeadControl(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: psc_head_direction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _PscKeyHeadControl__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_yzbot_msgs__msg__PscKeyHeadControl(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PscKeyHeadControl = {
  "yzbot_msgs::msg",
  "PscKeyHeadControl",
  _PscKeyHeadControl__cdr_serialize,
  _PscKeyHeadControl__cdr_deserialize,
  _PscKeyHeadControl__get_serialized_size,
  _PscKeyHeadControl__max_serialized_size
};

static rosidl_message_type_support_t _PscKeyHeadControl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PscKeyHeadControl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yzbot_msgs, msg, PscKeyHeadControl)() {
  return &_PscKeyHeadControl__type_support;
}

#if defined(__cplusplus)
}
#endif
