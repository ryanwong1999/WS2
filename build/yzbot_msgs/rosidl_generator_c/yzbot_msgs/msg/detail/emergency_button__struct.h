// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/EmergencyButton.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/EmergencyButton in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__EmergencyButton
{
  int32_t emergency_button;
} yzbot_msgs__msg__EmergencyButton;

// Struct for a sequence of yzbot_msgs__msg__EmergencyButton.
typedef struct yzbot_msgs__msg__EmergencyButton__Sequence
{
  yzbot_msgs__msg__EmergencyButton * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__EmergencyButton__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__EMERGENCY_BUTTON__STRUCT_H_
