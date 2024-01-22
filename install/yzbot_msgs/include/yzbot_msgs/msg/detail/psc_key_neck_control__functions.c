// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yzbot_msgs:msg/PscKeyNeckControl.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/psc_key_neck_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
yzbot_msgs__msg__PscKeyNeckControl__init(yzbot_msgs__msg__PscKeyNeckControl * msg)
{
  if (!msg) {
    return false;
  }
  // psc_neck_direction
  return true;
}

void
yzbot_msgs__msg__PscKeyNeckControl__fini(yzbot_msgs__msg__PscKeyNeckControl * msg)
{
  if (!msg) {
    return;
  }
  // psc_neck_direction
}

bool
yzbot_msgs__msg__PscKeyNeckControl__are_equal(const yzbot_msgs__msg__PscKeyNeckControl * lhs, const yzbot_msgs__msg__PscKeyNeckControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // psc_neck_direction
  if (lhs->psc_neck_direction != rhs->psc_neck_direction) {
    return false;
  }
  return true;
}

bool
yzbot_msgs__msg__PscKeyNeckControl__copy(
  const yzbot_msgs__msg__PscKeyNeckControl * input,
  yzbot_msgs__msg__PscKeyNeckControl * output)
{
  if (!input || !output) {
    return false;
  }
  // psc_neck_direction
  output->psc_neck_direction = input->psc_neck_direction;
  return true;
}

yzbot_msgs__msg__PscKeyNeckControl *
yzbot_msgs__msg__PscKeyNeckControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PscKeyNeckControl * msg = (yzbot_msgs__msg__PscKeyNeckControl *)allocator.allocate(sizeof(yzbot_msgs__msg__PscKeyNeckControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yzbot_msgs__msg__PscKeyNeckControl));
  bool success = yzbot_msgs__msg__PscKeyNeckControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yzbot_msgs__msg__PscKeyNeckControl__destroy(yzbot_msgs__msg__PscKeyNeckControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yzbot_msgs__msg__PscKeyNeckControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yzbot_msgs__msg__PscKeyNeckControl__Sequence__init(yzbot_msgs__msg__PscKeyNeckControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PscKeyNeckControl * data = NULL;

  if (size) {
    data = (yzbot_msgs__msg__PscKeyNeckControl *)allocator.zero_allocate(size, sizeof(yzbot_msgs__msg__PscKeyNeckControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yzbot_msgs__msg__PscKeyNeckControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yzbot_msgs__msg__PscKeyNeckControl__fini(&data[i - 1]);
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
yzbot_msgs__msg__PscKeyNeckControl__Sequence__fini(yzbot_msgs__msg__PscKeyNeckControl__Sequence * array)
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
      yzbot_msgs__msg__PscKeyNeckControl__fini(&array->data[i]);
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

yzbot_msgs__msg__PscKeyNeckControl__Sequence *
yzbot_msgs__msg__PscKeyNeckControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PscKeyNeckControl__Sequence * array = (yzbot_msgs__msg__PscKeyNeckControl__Sequence *)allocator.allocate(sizeof(yzbot_msgs__msg__PscKeyNeckControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yzbot_msgs__msg__PscKeyNeckControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yzbot_msgs__msg__PscKeyNeckControl__Sequence__destroy(yzbot_msgs__msg__PscKeyNeckControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yzbot_msgs__msg__PscKeyNeckControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yzbot_msgs__msg__PscKeyNeckControl__Sequence__are_equal(const yzbot_msgs__msg__PscKeyNeckControl__Sequence * lhs, const yzbot_msgs__msg__PscKeyNeckControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yzbot_msgs__msg__PscKeyNeckControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yzbot_msgs__msg__PscKeyNeckControl__Sequence__copy(
  const yzbot_msgs__msg__PscKeyNeckControl__Sequence * input,
  yzbot_msgs__msg__PscKeyNeckControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yzbot_msgs__msg__PscKeyNeckControl);
    yzbot_msgs__msg__PscKeyNeckControl * data =
      (yzbot_msgs__msg__PscKeyNeckControl *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yzbot_msgs__msg__PscKeyNeckControl__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          yzbot_msgs__msg__PscKeyNeckControl__fini(&data[i]);
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
    if (!yzbot_msgs__msg__PscKeyNeckControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
