// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from air_lab_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice
#include "air_lab_interfaces/msg/detail/goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `type`
// Member `object`
// Member `destination`
#include "rosidl_runtime_c/string_functions.h"

bool
air_lab_interfaces__msg__Goal__init(air_lab_interfaces__msg__Goal * msg)
{
  if (!msg) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    air_lab_interfaces__msg__Goal__fini(msg);
    return false;
  }
  // object
  if (!rosidl_runtime_c__String__init(&msg->object)) {
    air_lab_interfaces__msg__Goal__fini(msg);
    return false;
  }
  // destination
  if (!rosidl_runtime_c__String__init(&msg->destination)) {
    air_lab_interfaces__msg__Goal__fini(msg);
    return false;
  }
  return true;
}

void
air_lab_interfaces__msg__Goal__fini(air_lab_interfaces__msg__Goal * msg)
{
  if (!msg) {
    return;
  }
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // object
  rosidl_runtime_c__String__fini(&msg->object);
  // destination
  rosidl_runtime_c__String__fini(&msg->destination);
}

bool
air_lab_interfaces__msg__Goal__are_equal(const air_lab_interfaces__msg__Goal * lhs, const air_lab_interfaces__msg__Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // object
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object), &(rhs->object)))
  {
    return false;
  }
  // destination
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->destination), &(rhs->destination)))
  {
    return false;
  }
  return true;
}

bool
air_lab_interfaces__msg__Goal__copy(
  const air_lab_interfaces__msg__Goal * input,
  air_lab_interfaces__msg__Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // object
  if (!rosidl_runtime_c__String__copy(
      &(input->object), &(output->object)))
  {
    return false;
  }
  // destination
  if (!rosidl_runtime_c__String__copy(
      &(input->destination), &(output->destination)))
  {
    return false;
  }
  return true;
}

air_lab_interfaces__msg__Goal *
air_lab_interfaces__msg__Goal__create()
{
  air_lab_interfaces__msg__Goal * msg = (air_lab_interfaces__msg__Goal *)malloc(sizeof(air_lab_interfaces__msg__Goal));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(air_lab_interfaces__msg__Goal));
  bool success = air_lab_interfaces__msg__Goal__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
air_lab_interfaces__msg__Goal__destroy(air_lab_interfaces__msg__Goal * msg)
{
  if (msg) {
    air_lab_interfaces__msg__Goal__fini(msg);
  }
  free(msg);
}


bool
air_lab_interfaces__msg__Goal__Sequence__init(air_lab_interfaces__msg__Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  air_lab_interfaces__msg__Goal * data = NULL;
  if (size) {
    data = (air_lab_interfaces__msg__Goal *)calloc(size, sizeof(air_lab_interfaces__msg__Goal));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = air_lab_interfaces__msg__Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        air_lab_interfaces__msg__Goal__fini(&data[i - 1]);
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
air_lab_interfaces__msg__Goal__Sequence__fini(air_lab_interfaces__msg__Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      air_lab_interfaces__msg__Goal__fini(&array->data[i]);
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

air_lab_interfaces__msg__Goal__Sequence *
air_lab_interfaces__msg__Goal__Sequence__create(size_t size)
{
  air_lab_interfaces__msg__Goal__Sequence * array = (air_lab_interfaces__msg__Goal__Sequence *)malloc(sizeof(air_lab_interfaces__msg__Goal__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = air_lab_interfaces__msg__Goal__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
air_lab_interfaces__msg__Goal__Sequence__destroy(air_lab_interfaces__msg__Goal__Sequence * array)
{
  if (array) {
    air_lab_interfaces__msg__Goal__Sequence__fini(array);
  }
  free(array);
}

bool
air_lab_interfaces__msg__Goal__Sequence__are_equal(const air_lab_interfaces__msg__Goal__Sequence * lhs, const air_lab_interfaces__msg__Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!air_lab_interfaces__msg__Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
air_lab_interfaces__msg__Goal__Sequence__copy(
  const air_lab_interfaces__msg__Goal__Sequence * input,
  air_lab_interfaces__msg__Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(air_lab_interfaces__msg__Goal);
    air_lab_interfaces__msg__Goal * data =
      (air_lab_interfaces__msg__Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!air_lab_interfaces__msg__Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          air_lab_interfaces__msg__Goal__fini(&data[i]);
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
    if (!air_lab_interfaces__msg__Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
