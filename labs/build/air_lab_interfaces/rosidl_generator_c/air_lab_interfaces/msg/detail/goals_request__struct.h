// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__STRUCT_H_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goals'
#include "air_lab_interfaces/msg/detail/goal__struct.h"

// Struct defined in msg/GoalsRequest in the package air_lab_interfaces.
typedef struct air_lab_interfaces__msg__GoalsRequest
{
  air_lab_interfaces__msg__Goal__Sequence goals;
} air_lab_interfaces__msg__GoalsRequest;

// Struct for a sequence of air_lab_interfaces__msg__GoalsRequest.
typedef struct air_lab_interfaces__msg__GoalsRequest__Sequence
{
  air_lab_interfaces__msg__GoalsRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} air_lab_interfaces__msg__GoalsRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__STRUCT_H_
