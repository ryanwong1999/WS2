// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yzbot_msgs:msg/PscHeadControl.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/psc_head_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
yzbot_msgs__msg__PscHeadControl__init(yzbot_msgs__msg__PscHeadControl * msg)
{
  if (!msg) {
    return false;
  }
  // set_level
  // set_pitch
  return true;
}

void
yzbot_msgs__msg__PscHeadControl__fini(yzbot_msgs__msg__PscHeadControl * msg)
{
  if (!msg) {
    return;
  }
  // set_level
  // set_pitch
}

bool
yzbot_msgs__msg__PscHeadControl__are_equal(const yzbot_msgs__msg__PscHeadControl * lhs, const yzbot_msgs__msg__PscHeadControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // set_level
  if (lhs->set_level != rhs->set_level) {
    return false;
  }
  // set_pitch
  if (lhs->set_pitch != rhs->set_pitch) {
    return false;
  }
  return true;
}

bool
yzbot_msgs__msg__PscHeadControl__copy(
  const yzbot_msgs__msg__PscHeadControl * input,
  yzbot_msgs__msg__PscHeadControl * output)
{
  if (!input || !output) {
    return false;
  }
  // set_level
  output->set_level = input->set_level;
  // set_pitch
  output->set_pitch = input->set_pitch;
  return true;
}

yzbot_msgs__msg__PscHeadControl *
yzbot_msgs__msg__PscHeadControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PscHeadControl * msg = (yzbot_msgs__msg__PscHeadControl *)allocator.allocate(sizeof(yzbot_msgs__msg__PscHeadControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yzbot_msgs__msg__PscHeadControl));
  bool success = yzbot_msgs__msg__PscHeadControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yzbot_msgs__msg__PscHeadControl__destroy(yzbot_msgs__msg__PscHeadControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yzbot_msgs__msg__PscHeadControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yzbot_msgs__msg__PscHeadControl__Sequence__init(yzbot_msgs__msg__PscHeadControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PscHeadControl * data = NULL;

  if (size) {
    data = (yzbot_msgs__msg__PscHeadControl *)allocator.zero_allocate(size, sizeof(yzbot_msgs__msg__PscHeadControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yzbot_msgs__msg__PscHeadControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yzbot_msgs__msg__PscHeadControl__fini(&data[i - 1]);
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
yzbot_msgs__msg__PscHeadControl__Sequence__fini(yzbot_msgs__msg__PscHeadControl__Sequence * array)
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
      yzbot_msgs__msg__PscHeadControl__fini(&array->data[i]);
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

yzbot_msgs__msg__PscHeadControl__Sequence *
yzbot_msgs__msg__PscHeadControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PscHeadControl__Sequence * array = (yzbot_msgs__msg__PscHeadControl__Sequence *)allocator.allocate(sizeof(yzbot_msgs__msg__PscHeadControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yzbot_msgs__msg__PscHeadControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yzbot_msgs__msg__PscHeadControl__Sequence__destroy(yzbot_msgs__msg__PscHeadControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yzbot_msgs__msg__PscHeadControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yzbot_msgs__msg__PscHeadControl__Sequence__are_equal(const yzbot_msgs__msg__PscHeadControl__Sequence * lhs, const yzbot_msgs__msg__PscHeadControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yzbot_msgs__msg__PscHeadControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yzbot_msgs__msg__PscHeadControl__Sequence__copy(
  const yzbot_msgs__msg__PscHeadControl__Sequence * input,
  yzbot_msgs__msg__PscHeadControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yzbot_msgs__msg__PscHeadControl);
    yzbot_msgs__msg__PscHeadControl * data =
      (yzbot_msgs__msg__PscHeadControl *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yzbot_msgs__msg__PscHeadControl__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          yzbot_msgs__msg__PscHeadControl__fini(&data[i]);
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
    if (!yzbot_msgs__msg__PscHeadControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
