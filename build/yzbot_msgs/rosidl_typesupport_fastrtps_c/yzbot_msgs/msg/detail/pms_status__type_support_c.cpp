// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from yzbot_msgs:msg/PmsStatus.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/pms_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "yzbot_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yzbot_msgs/msg/detail/pms_status__struct.h"
#include "yzbot_msgs/msg/detail/pms_status__functions.h"
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


using _PmsStatus__ros_msg_type = yzbot_msgs__msg__PmsStatus;

static bool _PmsStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PmsStatus__ros_msg_type * ros_message = static_cast<const _PmsStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: pms_charging_flag
  {
    cdr << ros_message->pms_charging_flag;
  }

  // Field name: pms_battery_level
  {
    cdr << ros_message->pms_battery_level;
  }

  return true;
}

static bool _PmsStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PmsStatus__ros_msg_type * ros_message = static_cast<_PmsStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: pms_charging_flag
  {
    cdr >> ros_message->pms_charging_flag;
  }

  // Field name: pms_battery_level
  {
    cdr >> ros_message->pms_battery_level;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yzbot_msgs
size_t get_serialized_size_yzbot_msgs__msg__PmsStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PmsStatus__ros_msg_type * ros_message = static_cast<const _PmsStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pms_charging_flag
  {
    size_t item_size = sizeof(ros_message->pms_charging_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pms_battery_level
  {
    size_t item_size = sizeof(ros_message->pms_battery_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PmsStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yzbot_msgs__msg__PmsStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yzbot_msgs
size_t max_serialized_size_yzbot_msgs__msg__PmsStatus(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: pms_charging_flag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pms_battery_level
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _PmsStatus__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_yzbot_msgs__msg__PmsStatus(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PmsStatus = {
  "yzbot_msgs::msg",
  "PmsStatus",
  _PmsStatus__cdr_serialize,
  _PmsStatus__cdr_deserialize,
  _PmsStatus__get_serialized_size,
  _PmsStatus__max_serialized_size
};

static rosidl_message_type_support_t _PmsStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PmsStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yzbot_msgs, msg, PmsStatus)() {
  return &_PmsStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
