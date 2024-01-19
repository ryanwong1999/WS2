// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yzbot_msgs:msg/ChargeCtrl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yzbot_msgs/msg/detail/charge_ctrl__rosidl_typesupport_introspection_c.h"
#include "yzbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yzbot_msgs/msg/detail/charge_ctrl__functions.h"
#include "yzbot_msgs/msg/detail/charge_ctrl__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yzbot_msgs__msg__ChargeCtrl__init(message_memory);
}

void ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_fini_function(void * message_memory)
{
  yzbot_msgs__msg__ChargeCtrl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_member_array[1] = {
  {
    "auto_charge_flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs__msg__ChargeCtrl, auto_charge_flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_members = {
  "yzbot_msgs__msg",  // message namespace
  "ChargeCtrl",  // message name
  1,  // number of fields
  sizeof(yzbot_msgs__msg__ChargeCtrl),
  ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_member_array,  // message members
  ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_init_function,  // function to initialize message memory (memory has to be allocated)
  ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_type_support_handle = {
  0,
  &ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yzbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yzbot_msgs, msg, ChargeCtrl)() {
  if (!ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_type_support_handle.typesupport_identifier) {
    ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ChargeCtrl__rosidl_typesupport_introspection_c__ChargeCtrl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
