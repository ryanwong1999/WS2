// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yzbot_msgs:msg/FmqSet.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/fmq_set__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
yzbot_msgs__msg__FmqSet__init(yzbot_msgs__msg__FmqSet * msg)
{
  if (!msg) {
    return false;
  }
  // switch_status
  return true;
}

void
yzbot_msgs__msg__FmqSet__fini(yzbot_msgs__msg__FmqSet * msg)
{
  if (!msg) {
    return;
  }
  // switch_status
}

bool
yzbot_msgs__msg__FmqSet__are_equal(const yzbot_msgs__msg__FmqSet * lhs, const yzbot_msgs__msg__FmqSet * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // switch_status
  if (lhs->switch_status != rhs->switch_status) {
    return false;
  }
  return true;
}

bool
yzbot_msgs__msg__FmqSet__copy(
  const yzbot_msgs__msg__FmqSet * input,
  yzbot_msgs__msg__FmqSet * output)
{
  if (!input || !output) {
    return false;
  }
  // switch_status
  output->switch_status = input->switch_status;
  return true;
}

yzbot_msgs__msg__FmqSet *
yzbot_msgs__msg__FmqSet__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__FmqSet * msg = (yzbot_msgs__msg__FmqSet *)allocator.allocate(sizeof(yzbot_msgs__msg__FmqSet), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yzbot_msgs__msg__FmqSet));
  bool success = yzbot_msgs__msg__FmqSet__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yzbot_msgs__msg__FmqSet__destroy(yzbot_msgs__msg__FmqSet * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yzbot_msgs__msg__FmqSet__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yzbot_msgs__msg__FmqSet__Sequence__init(yzbot_msgs__msg__FmqSet__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__FmqSet * data = NULL;

  if (size) {
    data = (yzbot_msgs__msg__FmqSet *)allocator.zero_allocate(size, sizeof(yzbot_msgs__msg__FmqSet), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yzbot_msgs__msg__FmqSet__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yzbot_msgs__msg__FmqSet__fini(&data[i - 1]);
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
yzbot_msgs__msg__FmqSet__Sequence__fini(yzbot_msgs__msg__FmqSet__Sequence * array)
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
      yzbot_msgs__msg__FmqSet__fini(&array->data[i]);
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

yzbot_msgs__msg__FmqSet__Sequence *
yzbot_msgs__msg__FmqSet__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__FmqSet__Sequence * array = (yzbot_msgs__msg__FmqSet__Sequence *)allocator.allocate(sizeof(yzbot_msgs__msg__FmqSet__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yzbot_msgs__msg__FmqSet__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yzbot_msgs__msg__FmqSet__Sequence__destroy(yzbot_msgs__msg__FmqSet__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yzbot_msgs__msg__FmqSet__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yzbot_msgs__msg__FmqSet__Sequence__are_equal(const yzbot_msgs__msg__FmqSet__Sequence * lhs, const yzbot_msgs__msg__FmqSet__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yzbot_msgs__msg__FmqSet__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yzbot_msgs__msg__FmqSet__Sequence__copy(
  const yzbot_msgs__msg__FmqSet__Sequence * input,
  yzbot_msgs__msg__FmqSet__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yzbot_msgs__msg__FmqSet);
    yzbot_msgs__msg__FmqSet * data =
      (yzbot_msgs__msg__FmqSet *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yzbot_msgs__msg__FmqSet__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          yzbot_msgs__msg__FmqSet__fini(&data[i]);
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
    if (!yzbot_msgs__msg__FmqSet__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
