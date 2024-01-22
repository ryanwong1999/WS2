// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from yzbot_msgs:msg/PscKeyHeadControl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "yzbot_msgs/msg/detail/psc_key_head_control__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace yzbot_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PscKeyHeadControl_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) yzbot_msgs::msg::PscKeyHeadControl(_init);
}

void PscKeyHeadControl_fini_function(void * message_memory)
{
  auto typed_message = static_cast<yzbot_msgs::msg::PscKeyHeadControl *>(message_memory);
  typed_message->~PscKeyHeadControl();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PscKeyHeadControl_message_member_array[1] = {
  {
    "psc_head_direction",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yzbot_msgs::msg::PscKeyHeadControl, psc_head_direction),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PscKeyHeadControl_message_members = {
  "yzbot_msgs::msg",  // message namespace
  "PscKeyHeadControl",  // message name
  1,  // number of fields
  sizeof(yzbot_msgs::msg::PscKeyHeadControl),
  PscKeyHeadControl_message_member_array,  // message members
  PscKeyHeadControl_init_function,  // function to initialize message memory (memory has to be allocated)
  PscKeyHeadControl_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PscKeyHeadControl_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PscKeyHeadControl_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace yzbot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<yzbot_msgs::msg::PscKeyHeadControl>()
{
  return &::yzbot_msgs::msg::rosidl_typesupport_introspection_cpp::PscKeyHeadControl_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yzbot_msgs, msg, PscKeyHeadControl)() {
  return &::yzbot_msgs::msg::rosidl_typesupport_introspection_cpp::PscKeyHeadControl_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
