// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from yzbot_msgs:msg/PscHeadOffset.idl
// generated code does not contain a copyright notice

#ifndef YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__FUNCTIONS_H_
#define YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "yzbot_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "yzbot_msgs/msg/detail/psc_head_offset__struct.h"

/// Initialize msg/PscHeadOffset message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * yzbot_msgs__msg__PscHeadOffset
 * )) before or use
 * yzbot_msgs__msg__PscHeadOffset__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
bool
yzbot_msgs__msg__PscHeadOffset__init(yzbot_msgs__msg__PscHeadOffset * msg);

/// Finalize msg/PscHeadOffset message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
void
yzbot_msgs__msg__PscHeadOffset__fini(yzbot_msgs__msg__PscHeadOffset * msg);

/// Create msg/PscHeadOffset message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * yzbot_msgs__msg__PscHeadOffset__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
yzbot_msgs__msg__PscHeadOffset *
yzbot_msgs__msg__PscHeadOffset__create();

/// Destroy msg/PscHeadOffset message.
/**
 * It calls
 * yzbot_msgs__msg__PscHeadOffset__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
void
yzbot_msgs__msg__PscHeadOffset__destroy(yzbot_msgs__msg__PscHeadOffset * msg);

/// Check for msg/PscHeadOffset message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
bool
yzbot_msgs__msg__PscHeadOffset__are_equal(const yzbot_msgs__msg__PscHeadOffset * lhs, const yzbot_msgs__msg__PscHeadOffset * rhs);

/// Copy a msg/PscHeadOffset message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
bool
yzbot_msgs__msg__PscHeadOffset__copy(
  const yzbot_msgs__msg__PscHeadOffset * input,
  yzbot_msgs__msg__PscHeadOffset * output);

/// Initialize array of msg/PscHeadOffset messages.
/**
 * It allocates the memory for the number of elements and calls
 * yzbot_msgs__msg__PscHeadOffset__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
bool
yzbot_msgs__msg__PscHeadOffset__Sequence__init(yzbot_msgs__msg__PscHeadOffset__Sequence * array, size_t size);

/// Finalize array of msg/PscHeadOffset messages.
/**
 * It calls
 * yzbot_msgs__msg__PscHeadOffset__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
void
yzbot_msgs__msg__PscHeadOffset__Sequence__fini(yzbot_msgs__msg__PscHeadOffset__Sequence * array);

/// Create array of msg/PscHeadOffset messages.
/**
 * It allocates the memory for the array and calls
 * yzbot_msgs__msg__PscHeadOffset__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
yzbot_msgs__msg__PscHeadOffset__Sequence *
yzbot_msgs__msg__PscHeadOffset__Sequence__create(size_t size);

/// Destroy array of msg/PscHeadOffset messages.
/**
 * It calls
 * yzbot_msgs__msg__PscHeadOffset__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
void
yzbot_msgs__msg__PscHeadOffset__Sequence__destroy(yzbot_msgs__msg__PscHeadOffset__Sequence * array);

/// Check for msg/PscHeadOffset message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
bool
yzbot_msgs__msg__PscHeadOffset__Sequence__are_equal(const yzbot_msgs__msg__PscHeadOffset__Sequence * lhs, const yzbot_msgs__msg__PscHeadOffset__Sequence * rhs);

/// Copy an array of msg/PscHeadOffset messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_yzbot_msgs
bool
yzbot_msgs__msg__PscHeadOffset__Sequence__copy(
  const yzbot_msgs__msg__PscHeadOffset__Sequence * input,
  yzbot_msgs__msg__PscHeadOffset__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // YZBOT_MSGS__MSG__DETAIL__PSC_HEAD_OFFSET__FUNCTIONS_H_
