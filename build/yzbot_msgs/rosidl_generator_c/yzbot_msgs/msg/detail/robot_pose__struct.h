// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RobotPose in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__RobotPose
{
  float robot_x;
  float robot_y;
  float robot_yaw;
  float yaw;
  int8_t robot_state;
} yzbot_msgs__msg__RobotPose;

// Struct for a sequence of yzbot_msgs__msg__RobotPose.
typedef struct yzbot_msgs__msg__RobotPose__Sequence
{
  yzbot_msgs__msg__RobotPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__RobotPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__ROBOT_POSE__STRUCT_H_
