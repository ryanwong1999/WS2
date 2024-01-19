// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yzbot_msgs:msg/PmsStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yzbot_msgs/msg/detail/pms_status__rosidl_typesupport_introspection_c.h"
#include "yzbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yzbot_msgs/msg/detail/pms_status__functions.h"
#include "yzbot_msgs/msg/detail/pms_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yzbot_msgs__msg__PmsStatus__init(message_memory);
}

void PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_fini_function(void * message_memory)
{
  yzbot_msgs__msg__PmsStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_member_array[2] = {
  {
    "pms_charging_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs__msg__PmsStatus, pms_charging_flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pms_battery_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs__msg__PmsStatus, pms_battery_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_members = {
  "yzbot_msgs__msg",  // message namespace
  "PmsStatus",  // message name
  2,  // number of fields
  sizeof(yzbot_msgs__msg__PmsStatus),
  PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_member_array,  // message members
  PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_type_support_handle = {
  0,
  &PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yzbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yzbot_msgs, msg, PmsStatus)() {
  if (!PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_type_support_handle.typesupport_identifier) {
    PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PmsStatus__rosidl_typesupport_introspection_c__PmsStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
