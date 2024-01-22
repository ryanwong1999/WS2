// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/PscKeyNeckControl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_KEY_NECK_CONTROL__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__PSC_KEY_NECK_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/PscKeyNeckControl in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__PscKeyNeckControl
{
  int32_t psc_neck_direction;
} yzbot_msgs__msg__PscKeyNeckControl;

// Struct for a sequence of yzbot_msgs__msg__PscKeyNeckControl.
typedef struct yzbot_msgs__msg__PscKeyNeckControl__Sequence
{
  yzbot_msgs__msg__PscKeyNeckControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__PscKeyNeckControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_KEY_NECK_CONTROL__STRUCT_H_
