// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yzbot_msgs:msg/ChargeCtrl.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__CHARGE_CTRL__STRUCT_H_
#define YZBOT_MSGS__MSG__DETAIL__CHARGE_CTRL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ChargeCtrl in the package yzbot_msgs.
typedef struct yzbot_msgs__msg__ChargeCtrl
{
  int8_t auto_charge_flag;
} yzbot_msgs__msg__ChargeCtrl;

// Struct for a sequence of yzbot_msgs__msg__ChargeCtrl.
typedef struct yzbot_msgs__msg__ChargeCtrl__Sequence
{
  yzbot_msgs__msg__ChargeCtrl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yzbot_msgs__msg__ChargeCtrl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__CHARGE_CTRL__STRUCT_H_
