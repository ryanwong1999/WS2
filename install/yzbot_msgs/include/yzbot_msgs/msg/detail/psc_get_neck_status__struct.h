// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/PscGetNeckStatus.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/PscGetNeckStatus in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__PscGetNeckStatus
{
  int32_t get_height;
  int32_t get_limit;
  int32_t get_done;
} yzbot_msgs__msg__PscGetNeckStatus;

// Struct for a sequence of yzbot_msgs__msg__PscGetNeckStatus.
typedef struct yzbot_msgs__msg__PscGetNeckStatus__Sequence
{
  yzbot_msgs__msg__PscGetNeckStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__PscGetNeckStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_GET_NECK_STATUS__STRUCT_H_
