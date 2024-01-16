// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nav2_msgs:action/DummyRecovery.idl
// generated code does not contain a copyright notice

#ifndef NAV2_MSGS__ACTION__DETAIL__DUMMY_RECOVERY__FUNCTIONS_H_
#define NAV2_MSGS__ACTION__DETAIL__DUMMY_RECOVERY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nav2_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "nav2_msgs/action/detail/dummy_recovery__struct.h"

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_Goal
 * )) before or use
 * nav2_msgs__action__DummyRecovery_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Goal__init(nav2_msgs__action__DummyRecovery_Goal * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Goal__fini(nav2_msgs__action__DummyRecovery_Goal * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_Goal *
nav2_msgs__action__DummyRecovery_Goal__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Goal__destroy(nav2_msgs__action__DummyRecovery_Goal * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Goal__are_equal(const nav2_msgs__action__DummyRecovery_Goal * lhs, const nav2_msgs__action__DummyRecovery_Goal * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Goal__copy(
  const nav2_msgs__action__DummyRecovery_Goal * input,
  nav2_msgs__action__DummyRecovery_Goal * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Goal__Sequence__init(nav2_msgs__action__DummyRecovery_Goal__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Goal__Sequence__fini(nav2_msgs__action__DummyRecovery_Goal__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_Goal__Sequence *
nav2_msgs__action__DummyRecovery_Goal__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Goal__Sequence__destroy(nav2_msgs__action__DummyRecovery_Goal__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Goal__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_Goal__Sequence * lhs, const nav2_msgs__action__DummyRecovery_Goal__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Goal__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_Goal__Sequence * input,
  nav2_msgs__action__DummyRecovery_Goal__Sequence * output);

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_Result
 * )) before or use
 * nav2_msgs__action__DummyRecovery_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Result__init(nav2_msgs__action__DummyRecovery_Result * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Result__fini(nav2_msgs__action__DummyRecovery_Result * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_Result *
nav2_msgs__action__DummyRecovery_Result__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Result__destroy(nav2_msgs__action__DummyRecovery_Result * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Result__are_equal(const nav2_msgs__action__DummyRecovery_Result * lhs, const nav2_msgs__action__DummyRecovery_Result * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Result__copy(
  const nav2_msgs__action__DummyRecovery_Result * input,
  nav2_msgs__action__DummyRecovery_Result * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Result__Sequence__init(nav2_msgs__action__DummyRecovery_Result__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Result__Sequence__fini(nav2_msgs__action__DummyRecovery_Result__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_Result__Sequence *
nav2_msgs__action__DummyRecovery_Result__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Result__Sequence__destroy(nav2_msgs__action__DummyRecovery_Result__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Result__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_Result__Sequence * lhs, const nav2_msgs__action__DummyRecovery_Result__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Result__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_Result__Sequence * input,
  nav2_msgs__action__DummyRecovery_Result__Sequence * output);

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_Feedback
 * )) before or use
 * nav2_msgs__action__DummyRecovery_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Feedback__init(nav2_msgs__action__DummyRecovery_Feedback * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Feedback__fini(nav2_msgs__action__DummyRecovery_Feedback * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_Feedback *
nav2_msgs__action__DummyRecovery_Feedback__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Feedback__destroy(nav2_msgs__action__DummyRecovery_Feedback * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Feedback__are_equal(const nav2_msgs__action__DummyRecovery_Feedback * lhs, const nav2_msgs__action__DummyRecovery_Feedback * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Feedback__copy(
  const nav2_msgs__action__DummyRecovery_Feedback * input,
  nav2_msgs__action__DummyRecovery_Feedback * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Feedback__Sequence__init(nav2_msgs__action__DummyRecovery_Feedback__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Feedback__Sequence__fini(nav2_msgs__action__DummyRecovery_Feedback__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_Feedback__Sequence *
nav2_msgs__action__DummyRecovery_Feedback__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_Feedback__Sequence__destroy(nav2_msgs__action__DummyRecovery_Feedback__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Feedback__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_Feedback__Sequence * lhs, const nav2_msgs__action__DummyRecovery_Feedback__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_Feedback__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_Feedback__Sequence * input,
  nav2_msgs__action__DummyRecovery_Feedback__Sequence * output);

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_SendGoal_Request
 * )) before or use
 * nav2_msgs__action__DummyRecovery_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Request__init(nav2_msgs__action__DummyRecovery_SendGoal_Request * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Request__fini(nav2_msgs__action__DummyRecovery_SendGoal_Request * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_SendGoal_Request *
nav2_msgs__action__DummyRecovery_SendGoal_Request__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Request__destroy(nav2_msgs__action__DummyRecovery_SendGoal_Request * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Request__are_equal(const nav2_msgs__action__DummyRecovery_SendGoal_Request * lhs, const nav2_msgs__action__DummyRecovery_SendGoal_Request * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Request__copy(
  const nav2_msgs__action__DummyRecovery_SendGoal_Request * input,
  nav2_msgs__action__DummyRecovery_SendGoal_Request * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__init(nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__fini(nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence *
nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__destroy(nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence * lhs, const nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence * input,
  nav2_msgs__action__DummyRecovery_SendGoal_Request__Sequence * output);

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_SendGoal_Response
 * )) before or use
 * nav2_msgs__action__DummyRecovery_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Response__init(nav2_msgs__action__DummyRecovery_SendGoal_Response * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Response__fini(nav2_msgs__action__DummyRecovery_SendGoal_Response * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_SendGoal_Response *
nav2_msgs__action__DummyRecovery_SendGoal_Response__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Response__destroy(nav2_msgs__action__DummyRecovery_SendGoal_Response * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Response__are_equal(const nav2_msgs__action__DummyRecovery_SendGoal_Response * lhs, const nav2_msgs__action__DummyRecovery_SendGoal_Response * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Response__copy(
  const nav2_msgs__action__DummyRecovery_SendGoal_Response * input,
  nav2_msgs__action__DummyRecovery_SendGoal_Response * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__init(nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__fini(nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence *
nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__destroy(nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence * lhs, const nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence * input,
  nav2_msgs__action__DummyRecovery_SendGoal_Response__Sequence * output);

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_GetResult_Request
 * )) before or use
 * nav2_msgs__action__DummyRecovery_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Request__init(nav2_msgs__action__DummyRecovery_GetResult_Request * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Request__fini(nav2_msgs__action__DummyRecovery_GetResult_Request * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_GetResult_Request *
nav2_msgs__action__DummyRecovery_GetResult_Request__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Request__destroy(nav2_msgs__action__DummyRecovery_GetResult_Request * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Request__are_equal(const nav2_msgs__action__DummyRecovery_GetResult_Request * lhs, const nav2_msgs__action__DummyRecovery_GetResult_Request * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Request__copy(
  const nav2_msgs__action__DummyRecovery_GetResult_Request * input,
  nav2_msgs__action__DummyRecovery_GetResult_Request * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__init(nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__fini(nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence *
nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__destroy(nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence * lhs, const nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence * input,
  nav2_msgs__action__DummyRecovery_GetResult_Request__Sequence * output);

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_GetResult_Response
 * )) before or use
 * nav2_msgs__action__DummyRecovery_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Response__init(nav2_msgs__action__DummyRecovery_GetResult_Response * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Response__fini(nav2_msgs__action__DummyRecovery_GetResult_Response * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_GetResult_Response *
nav2_msgs__action__DummyRecovery_GetResult_Response__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Response__destroy(nav2_msgs__action__DummyRecovery_GetResult_Response * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Response__are_equal(const nav2_msgs__action__DummyRecovery_GetResult_Response * lhs, const nav2_msgs__action__DummyRecovery_GetResult_Response * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Response__copy(
  const nav2_msgs__action__DummyRecovery_GetResult_Response * input,
  nav2_msgs__action__DummyRecovery_GetResult_Response * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__init(nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__fini(nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence *
nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__destroy(nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence * lhs, const nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence * input,
  nav2_msgs__action__DummyRecovery_GetResult_Response__Sequence * output);

/// Initialize action/DummyRecovery message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nav2_msgs__action__DummyRecovery_FeedbackMessage
 * )) before or use
 * nav2_msgs__action__DummyRecovery_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_FeedbackMessage__init(nav2_msgs__action__DummyRecovery_FeedbackMessage * msg);

/// Finalize action/DummyRecovery message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_FeedbackMessage__fini(nav2_msgs__action__DummyRecovery_FeedbackMessage * msg);

/// Create action/DummyRecovery message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nav2_msgs__action__DummyRecovery_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_FeedbackMessage *
nav2_msgs__action__DummyRecovery_FeedbackMessage__create();

/// Destroy action/DummyRecovery message.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_FeedbackMessage__destroy(nav2_msgs__action__DummyRecovery_FeedbackMessage * msg);

/// Check for action/DummyRecovery message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_FeedbackMessage__are_equal(const nav2_msgs__action__DummyRecovery_FeedbackMessage * lhs, const nav2_msgs__action__DummyRecovery_FeedbackMessage * rhs);

/// Copy a action/DummyRecovery message.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_FeedbackMessage__copy(
  const nav2_msgs__action__DummyRecovery_FeedbackMessage * input,
  nav2_msgs__action__DummyRecovery_FeedbackMessage * output);

/// Initialize array of action/DummyRecovery messages.
/**
 * It allocates the memory for the number of elements and calls
 * nav2_msgs__action__DummyRecovery_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__init(nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__fini(nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence * array);

/// Create array of action/DummyRecovery messages.
/**
 * It allocates the memory for the array and calls
 * nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence *
nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/DummyRecovery messages.
/**
 * It calls
 * nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
void
nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__destroy(nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence * array);

/// Check for action/DummyRecovery message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__are_equal(const nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence * lhs, const nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/DummyRecovery messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nav2_msgs
bool
nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence__copy(
  const nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence * input,
  nav2_msgs__action__DummyRecovery_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NAV2_MSGS__ACTION__DETAIL__DUMMY_RECOVERY__FUNCTIONS_H_
