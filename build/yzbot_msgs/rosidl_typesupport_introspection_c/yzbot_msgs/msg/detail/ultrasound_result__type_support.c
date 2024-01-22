// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yzbot_msgs:msg/UltrasoundResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yzbot_msgs/msg/detail/ultrasound_result__rosidl_typesupport_introspection_c.h"
#include "yzbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yzbot_msgs/msg/detail/ultrasound_result__functions.h"
#include "yzbot_msgs/msg/detail/ultrasound_result__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yzbot_msgs__msg__UltrasoundResult__init(message_memory);
}

void UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_fini_function(void * message_memory)
{
  yzbot_msgs__msg__UltrasoundResult__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_member_array[2] = {
  {
    "cs_obs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs__msg__UltrasoundResult, cs_obs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fz_obs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs__msg__UltrasoundResult, fz_obs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_members = {
  "yzbot_msgs__msg",  // message namespace
  "UltrasoundResult",  // message name
  2,  // number of fields
  sizeof(yzbot_msgs__msg__UltrasoundResult),
  UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_member_array,  // message members
  UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_init_function,  // function to initialize message memory (memory has to be allocated)
  UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_type_support_handle = {
  0,
  &UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yzbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yzbot_msgs, msg, UltrasoundResult)() {
  if (!UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_type_support_handle.typesupport_identifier) {
    UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &UltrasoundResult__rosidl_typesupport_introspection_c__UltrasoundResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
