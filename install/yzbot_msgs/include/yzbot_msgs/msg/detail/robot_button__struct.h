// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/RobotButton.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RobotButton in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__RobotButton
{
  int32_t button_audio;
  int32_t button_power;
  int32_t zs;
} yzbot_msgs__msg__RobotButton;

// Struct for a sequence of yzbot_msgs__msg__RobotButton.
typedef struct yzbot_msgs__msg__RobotButton__Sequence
{
  yzbot_msgs__msg__RobotButton * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__RobotButton__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__ROBOT_BUTTON__STRUCT_H_
