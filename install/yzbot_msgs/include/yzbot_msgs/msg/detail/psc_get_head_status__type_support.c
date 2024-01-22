// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yzbot_msgs:msg/PscGetHeadStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yzbot_msgs/msg/detail/psc_get_head_status__rosidl_typesupport_introspection_c.h"
#include "yzbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yzbot_msgs/msg/detail/psc_get_head_status__functions.h"
#include "yzbot_msgs/msg/detail/psc_get_head_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yzbot_msgs__msg__PscGetHeadStatus__init(message_memory);
}

void PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_fini_function(void * message_memory)
{
  yzbot_msgs__msg__PscGetHeadStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_member_array[2] = {
  {
    "get_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs__msg__PscGetHeadStatus, get_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "get_pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs__msg__PscGetHeadStatus, get_pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_members = {
  "yzbot_msgs__msg",  // message namespace
  "PscGetHeadStatus",  // message name
  2,  // number of fields
  sizeof(yzbot_msgs__msg__PscGetHeadStatus),
  PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_member_array,  // message members
  PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_type_support_handle = {
  0,
  &PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yzbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yzbot_msgs, msg, PscGetHeadStatus)() {
  if (!PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_type_support_handle.typesupport_identifier) {
    PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PscGetHeadStatus__rosidl_typesupport_introspection_c__PscGetHeadStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
