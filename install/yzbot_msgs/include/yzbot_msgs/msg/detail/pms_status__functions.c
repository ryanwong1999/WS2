// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yzbot_msgs:msg/PmsStatus.idl
// generated code does not contain a copyright notice
#include "yzbot_msgs/msg/detail/pms_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
yzbot_msgs__msg__PmsStatus__init(yzbot_msgs__msg__PmsStatus * msg)
{
  if (!msg) {
    return false;
  }
  // pms_charging_flag
  // pms_battery_level
  return true;
}

void
yzbot_msgs__msg__PmsStatus__fini(yzbot_msgs__msg__PmsStatus * msg)
{
  if (!msg) {
    return;
  }
  // pms_charging_flag
  // pms_battery_level
}

bool
yzbot_msgs__msg__PmsStatus__are_equal(const yzbot_msgs__msg__PmsStatus * lhs, const yzbot_msgs__msg__PmsStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pms_charging_flag
  if (lhs->pms_charging_flag != rhs->pms_charging_flag) {
    return false;
  }
  // pms_battery_level
  if (lhs->pms_battery_level != rhs->pms_battery_level) {
    return false;
  }
  return true;
}

bool
yzbot_msgs__msg__PmsStatus__copy(
  const yzbot_msgs__msg__PmsStatus * input,
  yzbot_msgs__msg__PmsStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // pms_charging_flag
  output->pms_charging_flag = input->pms_charging_flag;
  // pms_battery_level
  output->pms_battery_level = input->pms_battery_level;
  return true;
}

yzbot_msgs__msg__PmsStatus *
yzbot_msgs__msg__PmsStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PmsStatus * msg = (yzbot_msgs__msg__PmsStatus *)allocator.allocate(sizeof(yzbot_msgs__msg__PmsStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yzbot_msgs__msg__PmsStatus));
  bool success = yzbot_msgs__msg__PmsStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yzbot_msgs__msg__PmsStatus__destroy(yzbot_msgs__msg__PmsStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yzbot_msgs__msg__PmsStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yzbot_msgs__msg__PmsStatus__Sequence__init(yzbot_msgs__msg__PmsStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PmsStatus * data = NULL;

  if (size) {
    data = (yzbot_msgs__msg__PmsStatus *)allocator.zero_allocate(size, sizeof(yzbot_msgs__msg__PmsStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yzbot_msgs__msg__PmsStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yzbot_msgs__msg__PmsStatus__fini(&data[i - 1]);
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
yzbot_msgs__msg__PmsStatus__Sequence__fini(yzbot_msgs__msg__PmsStatus__Sequence * array)
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
      yzbot_msgs__msg__PmsStatus__fini(&array->data[i]);
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

yzbot_msgs__msg__PmsStatus__Sequence *
yzbot_msgs__msg__PmsStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yzbot_msgs__msg__PmsStatus__Sequence * array = (yzbot_msgs__msg__PmsStatus__Sequence *)allocator.allocate(sizeof(yzbot_msgs__msg__PmsStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yzbot_msgs__msg__PmsStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yzbot_msgs__msg__PmsStatus__Sequence__destroy(yzbot_msgs__msg__PmsStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yzbot_msgs__msg__PmsStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yzbot_msgs__msg__PmsStatus__Sequence__are_equal(const yzbot_msgs__msg__PmsStatus__Sequence * lhs, const yzbot_msgs__msg__PmsStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yzbot_msgs__msg__PmsStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yzbot_msgs__msg__PmsStatus__Sequence__copy(
  const yzbot_msgs__msg__PmsStatus__Sequence * input,
  yzbot_msgs__msg__PmsStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yzbot_msgs__msg__PmsStatus);
    yzbot_msgs__msg__PmsStatus * data =
      (yzbot_msgs__msg__PmsStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yzbot_msgs__msg__PmsStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          yzbot_msgs__msg__PmsStatus__fini(&data[i]);
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
    if (!yzbot_msgs__msg__PmsStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
