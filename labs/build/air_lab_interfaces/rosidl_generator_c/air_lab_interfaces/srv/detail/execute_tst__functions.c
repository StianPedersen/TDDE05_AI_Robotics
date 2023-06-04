// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from air_lab_interfaces:srv/ExecuteTst.idl
// generated code does not contain a copyright notice
#include "air_lab_interfaces/srv/detail/execute_tst__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `tst_file`
#include "rosidl_runtime_c/string_functions.h"

bool
air_lab_interfaces__srv__ExecuteTst_Request__init(air_lab_interfaces__srv__ExecuteTst_Request * msg)
{
  if (!msg) {
    return false;
  }
  // tst_file
  if (!rosidl_runtime_c__String__init(&msg->tst_file)) {
    air_lab_interfaces__srv__ExecuteTst_Request__fini(msg);
    return false;
  }
  return true;
}

void
air_lab_interfaces__srv__ExecuteTst_Request__fini(air_lab_interfaces__srv__ExecuteTst_Request * msg)
{
  if (!msg) {
    return;
  }
  // tst_file
  rosidl_runtime_c__String__fini(&msg->tst_file);
}

bool
air_lab_interfaces__srv__ExecuteTst_Request__are_equal(const air_lab_interfaces__srv__ExecuteTst_Request * lhs, const air_lab_interfaces__srv__ExecuteTst_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tst_file
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tst_file), &(rhs->tst_file)))
  {
    return false;
  }
  return true;
}

bool
air_lab_interfaces__srv__ExecuteTst_Request__copy(
  const air_lab_interfaces__srv__ExecuteTst_Request * input,
  air_lab_interfaces__srv__ExecuteTst_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // tst_file
  if (!rosidl_runtime_c__String__copy(
      &(input->tst_file), &(output->tst_file)))
  {
    return false;
  }
  return true;
}

air_lab_interfaces__srv__ExecuteTst_Request *
air_lab_interfaces__srv__ExecuteTst_Request__create()
{
  air_lab_interfaces__srv__ExecuteTst_Request * msg = (air_lab_interfaces__srv__ExecuteTst_Request *)malloc(sizeof(air_lab_interfaces__srv__ExecuteTst_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(air_lab_interfaces__srv__ExecuteTst_Request));
  bool success = air_lab_interfaces__srv__ExecuteTst_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
air_lab_interfaces__srv__ExecuteTst_Request__destroy(air_lab_interfaces__srv__ExecuteTst_Request * msg)
{
  if (msg) {
    air_lab_interfaces__srv__ExecuteTst_Request__fini(msg);
  }
  free(msg);
}


bool
air_lab_interfaces__srv__ExecuteTst_Request__Sequence__init(air_lab_interfaces__srv__ExecuteTst_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  air_lab_interfaces__srv__ExecuteTst_Request * data = NULL;
  if (size) {
    data = (air_lab_interfaces__srv__ExecuteTst_Request *)calloc(size, sizeof(air_lab_interfaces__srv__ExecuteTst_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = air_lab_interfaces__srv__ExecuteTst_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        air_lab_interfaces__srv__ExecuteTst_Request__fini(&data[i - 1]);
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
air_lab_interfaces__srv__ExecuteTst_Request__Sequence__fini(air_lab_interfaces__srv__ExecuteTst_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      air_lab_interfaces__srv__ExecuteTst_Request__fini(&array->data[i]);
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

air_lab_interfaces__srv__ExecuteTst_Request__Sequence *
air_lab_interfaces__srv__ExecuteTst_Request__Sequence__create(size_t size)
{
  air_lab_interfaces__srv__ExecuteTst_Request__Sequence * array = (air_lab_interfaces__srv__ExecuteTst_Request__Sequence *)malloc(sizeof(air_lab_interfaces__srv__ExecuteTst_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = air_lab_interfaces__srv__ExecuteTst_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
air_lab_interfaces__srv__ExecuteTst_Request__Sequence__destroy(air_lab_interfaces__srv__ExecuteTst_Request__Sequence * array)
{
  if (array) {
    air_lab_interfaces__srv__ExecuteTst_Request__Sequence__fini(array);
  }
  free(array);
}

bool
air_lab_interfaces__srv__ExecuteTst_Request__Sequence__are_equal(const air_lab_interfaces__srv__ExecuteTst_Request__Sequence * lhs, const air_lab_interfaces__srv__ExecuteTst_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!air_lab_interfaces__srv__ExecuteTst_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
air_lab_interfaces__srv__ExecuteTst_Request__Sequence__copy(
  const air_lab_interfaces__srv__ExecuteTst_Request__Sequence * input,
  air_lab_interfaces__srv__ExecuteTst_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(air_lab_interfaces__srv__ExecuteTst_Request);
    air_lab_interfaces__srv__ExecuteTst_Request * data =
      (air_lab_interfaces__srv__ExecuteTst_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!air_lab_interfaces__srv__ExecuteTst_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          air_lab_interfaces__srv__ExecuteTst_Request__fini(&data[i]);
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
    if (!air_lab_interfaces__srv__ExecuteTst_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `my_error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
air_lab_interfaces__srv__ExecuteTst_Response__init(air_lab_interfaces__srv__ExecuteTst_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // my_error
  if (!rosidl_runtime_c__String__init(&msg->my_error)) {
    air_lab_interfaces__srv__ExecuteTst_Response__fini(msg);
    return false;
  }
  return true;
}

void
air_lab_interfaces__srv__ExecuteTst_Response__fini(air_lab_interfaces__srv__ExecuteTst_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // my_error
  rosidl_runtime_c__String__fini(&msg->my_error);
}

bool
air_lab_interfaces__srv__ExecuteTst_Response__are_equal(const air_lab_interfaces__srv__ExecuteTst_Response * lhs, const air_lab_interfaces__srv__ExecuteTst_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // my_error
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->my_error), &(rhs->my_error)))
  {
    return false;
  }
  return true;
}

bool
air_lab_interfaces__srv__ExecuteTst_Response__copy(
  const air_lab_interfaces__srv__ExecuteTst_Response * input,
  air_lab_interfaces__srv__ExecuteTst_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // my_error
  if (!rosidl_runtime_c__String__copy(
      &(input->my_error), &(output->my_error)))
  {
    return false;
  }
  return true;
}

air_lab_interfaces__srv__ExecuteTst_Response *
air_lab_interfaces__srv__ExecuteTst_Response__create()
{
  air_lab_interfaces__srv__ExecuteTst_Response * msg = (air_lab_interfaces__srv__ExecuteTst_Response *)malloc(sizeof(air_lab_interfaces__srv__ExecuteTst_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(air_lab_interfaces__srv__ExecuteTst_Response));
  bool success = air_lab_interfaces__srv__ExecuteTst_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
air_lab_interfaces__srv__ExecuteTst_Response__destroy(air_lab_interfaces__srv__ExecuteTst_Response * msg)
{
  if (msg) {
    air_lab_interfaces__srv__ExecuteTst_Response__fini(msg);
  }
  free(msg);
}


bool
air_lab_interfaces__srv__ExecuteTst_Response__Sequence__init(air_lab_interfaces__srv__ExecuteTst_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  air_lab_interfaces__srv__ExecuteTst_Response * data = NULL;
  if (size) {
    data = (air_lab_interfaces__srv__ExecuteTst_Response *)calloc(size, sizeof(air_lab_interfaces__srv__ExecuteTst_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = air_lab_interfaces__srv__ExecuteTst_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        air_lab_interfaces__srv__ExecuteTst_Response__fini(&data[i - 1]);
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
air_lab_interfaces__srv__ExecuteTst_Response__Sequence__fini(air_lab_interfaces__srv__ExecuteTst_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      air_lab_interfaces__srv__ExecuteTst_Response__fini(&array->data[i]);
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

air_lab_interfaces__srv__ExecuteTst_Response__Sequence *
air_lab_interfaces__srv__ExecuteTst_Response__Sequence__create(size_t size)
{
  air_lab_interfaces__srv__ExecuteTst_Response__Sequence * array = (air_lab_interfaces__srv__ExecuteTst_Response__Sequence *)malloc(sizeof(air_lab_interfaces__srv__ExecuteTst_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = air_lab_interfaces__srv__ExecuteTst_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
air_lab_interfaces__srv__ExecuteTst_Response__Sequence__destroy(air_lab_interfaces__srv__ExecuteTst_Response__Sequence * array)
{
  if (array) {
    air_lab_interfaces__srv__ExecuteTst_Response__Sequence__fini(array);
  }
  free(array);
}

bool
air_lab_interfaces__srv__ExecuteTst_Response__Sequence__are_equal(const air_lab_interfaces__srv__ExecuteTst_Response__Sequence * lhs, const air_lab_interfaces__srv__ExecuteTst_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!air_lab_interfaces__srv__ExecuteTst_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
air_lab_interfaces__srv__ExecuteTst_Response__Sequence__copy(
  const air_lab_interfaces__srv__ExecuteTst_Response__Sequence * input,
  air_lab_interfaces__srv__ExecuteTst_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(air_lab_interfaces__srv__ExecuteTst_Response);
    air_lab_interfaces__srv__ExecuteTst_Response * data =
      (air_lab_interfaces__srv__ExecuteTst_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!air_lab_interfaces__srv__ExecuteTst_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          air_lab_interfaces__srv__ExecuteTst_Response__fini(&data[i]);
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
    if (!air_lab_interfaces__srv__ExecuteTst_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
