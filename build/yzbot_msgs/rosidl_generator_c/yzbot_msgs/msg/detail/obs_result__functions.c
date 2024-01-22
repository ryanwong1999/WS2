// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yzbot_msgs:msg/ObsResult.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/obs_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
yzbot_msgs__msg__ObsResult__init(yzbot_msgs__msg__ObsResult * msg)
{
  if (!msg) {
    return false;
  }
  // cs_obs
  // fz_obs
  return true;
}

void
yzbot_msgs__msg__ObsResult__fini(yzbot_msgs__msg__ObsResult * msg)
{
  if (!msg) {
    return;
  }
  // cs_obs
  // fz_obs
}

bool
yzbot_msgs__msg__ObsResult__are_equal(const yzbot_msgs__msg__ObsResult * lhs, const yzbot_msgs__msg__ObsResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cs_obs
  if (lhs->cs_obs != rhs->cs_obs) {
    return false;
  }
  // fz_obs
  if (lhs->fz_obs != rhs->fz_obs) {
    return false;
  }
  return true;
}

bool
yzbot_msgs__msg__ObsResult__copy(
  const yzbot_msgs__msg__ObsResult * input,
  yzbot_msgs__msg__ObsResult * output)
{
  if (!input || !output) {
    return false;
  }
  // cs_obs
  output->cs_obs = input->cs_obs;
  // fz_obs
  output->fz_obs = input->fz_obs;
  return true;
}

yzbot_msgs__msg__ObsResult *
yzbot_msgs__msg__ObsResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__ObsResult * msg = (yzbot_msgs__msg__ObsResult *)allocator.allocate(sizeof(yzbot_msgs__msg__ObsResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yzbot_msgs__msg__ObsResult));
  bool success = yzbot_msgs__msg__ObsResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yzbot_msgs__msg__ObsResult__destroy(yzbot_msgs__msg__ObsResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yzbot_msgs__msg__ObsResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yzbot_msgs__msg__ObsResult__Sequence__init(yzbot_msgs__msg__ObsResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__ObsResult * data = NULL;

  if (size) {
    data = (yzbot_msgs__msg__ObsResult *)allocator.zero_allocate(size, sizeof(yzbot_msgs__msg__ObsResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yzbot_msgs__msg__ObsResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yzbot_msgs__msg__ObsResult__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
yzbot_msgs__msg__ObsResult__Sequence__fini(yzbot_msgs__msg__ObsResult__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      yzbot_msgs__msg__ObsResult__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

yzbot_msgs__msg__ObsResult__Sequence *
yzbot_msgs__msg__ObsResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__ObsResult__Sequence * array = (yzbot_msgs__msg__ObsResult__Sequence *)allocator.allocate(sizeof(yzbot_msgs__msg__ObsResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yzbot_msgs__msg__ObsResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yzbot_msgs__msg__ObsResult__Sequence__destroy(yzbot_msgs__msg__ObsResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yzbot_msgs__msg__ObsResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yzbot_msgs__msg__ObsResult__Sequence__are_equal(const yzbot_msgs__msg__ObsResult__Sequence * lhs, const yzbot_msgs__msg__ObsResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yzbot_msgs__msg__ObsResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yzbot_msgs__msg__ObsResult__Sequence__copy(
  const yzbot_msgs__msg__ObsResult__Sequence * input,
  yzbot_msgs__msg__ObsResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yzbot_msgs__msg__ObsResult);
    yzbot_msgs__msg__ObsResult * data =
      (yzbot_msgs__msg__ObsResult *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yzbot_msgs__msg__ObsResult__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          yzbot_msgs__msg__ObsResult__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yzbot_msgs__msg__ObsResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
