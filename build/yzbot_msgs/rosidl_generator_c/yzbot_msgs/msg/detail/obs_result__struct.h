// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/ObsResult.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__OBS_RESULT__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__OBS_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ObsResult in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__ObsResult
{
  int8_t cs_obs;
  int8_t fz_obs;
} yzbot_msgs__msg__ObsResult;

// Struct for a sequence of yzbot_msgs__msg__ObsResult.
typedef struct yzbot_msgs__msg__ObsResult__Sequence
{
  yzbot_msgs__msg__ObsResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__ObsResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__OBS_RESULT__STRUCT_H_
