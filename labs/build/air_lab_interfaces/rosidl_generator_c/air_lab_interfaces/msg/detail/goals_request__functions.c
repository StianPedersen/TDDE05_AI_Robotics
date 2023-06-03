// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice
#include "air_lab_interfaces/msg/detail/goals_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `goals`
#include "air_lab_interfaces/msg/detail/goal__functions.h"

bool
air_lab_interfaces__msg__GoalsRequest__init(air_lab_interfaces__msg__GoalsRequest * msg)
{
  if (!msg) {
    return false;
  }
  // goals
  if (!air_lab_interfaces__msg__Goal__Sequence__init(&msg->goals, 0)) {
    air_lab_interfaces__msg__GoalsRequest__fini(msg);
    return false;
  }
  return true;
}

void
air_lab_interfaces__msg__GoalsRequest__fini(air_lab_interfaces__msg__GoalsRequest * msg)
{
  if (!msg) {
    return;
  }
  // goals
  air_lab_interfaces__msg__Goal__Sequence__fini(&msg->goals);
}

bool
air_lab_interfaces__msg__GoalsRequest__are_equal(const air_lab_interfaces__msg__GoalsRequest * lhs, const air_lab_interfaces__msg__GoalsRequest * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goals
  if (!air_lab_interfaces__msg__Goal__Sequence__are_equal(
      &(lhs->goals), &(rhs->goals)))
  {
    return false;
  }
  return true;
}

bool
air_lab_interfaces__msg__GoalsRequest__copy(
  const air_lab_interfaces__msg__GoalsRequest * input,
  air_lab_interfaces__msg__GoalsRequest * output)
{
  if (!input || !output) {
    return false;
  }
  // goals
  if (!air_lab_interfaces__msg__Goal__Sequence__copy(
      &(input->goals), &(output->goals)))
  {
    return false;
  }
  return true;
}

air_lab_interfaces__msg__GoalsRequest *
air_lab_interfaces__msg__GoalsRequest__create()
{
  air_lab_interfaces__msg__GoalsRequest * msg = (air_lab_interfaces__msg__GoalsRequest *)malloc(sizeof(air_lab_interfaces__msg__GoalsRequest));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(air_lab_interfaces__msg__GoalsRequest));
  bool success = air_lab_interfaces__msg__GoalsRequest__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
air_lab_interfaces__msg__GoalsRequest__destroy(air_lab_interfaces__msg__GoalsRequest * msg)
{
  if (msg) {
    air_lab_interfaces__msg__GoalsRequest__fini(msg);
  }
  free(msg);
}


bool
air_lab_interfaces__msg__GoalsRequest__Sequence__init(air_lab_interfaces__msg__GoalsRequest__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  air_lab_interfaces__msg__GoalsRequest * data = NULL;
  if (size) {
    data = (air_lab_interfaces__msg__GoalsRequest *)calloc(size, sizeof(air_lab_interfaces__msg__GoalsRequest));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = air_lab_interfaces__msg__GoalsRequest__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        air_lab_interfaces__msg__GoalsRequest__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
air_lab_interfaces__msg__GoalsRequest__Sequence__fini(air_lab_interfaces__msg__GoalsRequest__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      air_lab_interfaces__msg__GoalsRequest__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

air_lab_interfaces__msg__GoalsRequest__Sequence *
air_lab_interfaces__msg__GoalsRequest__Sequence__create(size_t size)
{
  air_lab_interfaces__msg__GoalsRequest__Sequence * array = (air_lab_interfaces__msg__GoalsRequest__Sequence *)malloc(sizeof(air_lab_interfaces__msg__GoalsRequest__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = air_lab_interfaces__msg__GoalsRequest__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
air_lab_interfaces__msg__GoalsRequest__Sequence__destroy(air_lab_interfaces__msg__GoalsRequest__Sequence * array)
{
  if (array) {
    air_lab_interfaces__msg__GoalsRequest__Sequence__fini(array);
  }
  free(array);
}

bool
air_lab_interfaces__msg__GoalsRequest__Sequence__are_equal(const air_lab_interfaces__msg__GoalsRequest__Sequence * lhs, const air_lab_interfaces__msg__GoalsRequest__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!air_lab_interfaces__msg__GoalsRequest__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
air_lab_interfaces__msg__GoalsRequest__Sequence__copy(
  const air_lab_interfaces__msg__GoalsRequest__Sequence * input,
  air_lab_interfaces__msg__GoalsRequest__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(air_lab_interfaces__msg__GoalsRequest);
    air_lab_interfaces__msg__GoalsRequest * data =
      (air_lab_interfaces__msg__GoalsRequest *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!air_lab_interfaces__msg__GoalsRequest__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          air_lab_interfaces__msg__GoalsRequest__fini(&data[i]);
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
    if (!air_lab_interfaces__msg__GoalsRequest__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
