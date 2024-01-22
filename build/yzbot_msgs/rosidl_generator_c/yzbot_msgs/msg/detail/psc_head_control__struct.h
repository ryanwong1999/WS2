// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/PscHeadControl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/PscHeadControl in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__PscHeadControl
{
  int32_t set_level;
  int32_t set_pitch;
} yzbot_msgs__msg__PscHeadControl;

// Struct for a sequence of yzbot_msgs__msg__PscHeadControl.
typedef struct yzbot_msgs__msg__PscHeadControl__Sequence
{
  yzbot_msgs__msg__PscHeadControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__PscHeadControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_CONTROL__STRUCT_H_
