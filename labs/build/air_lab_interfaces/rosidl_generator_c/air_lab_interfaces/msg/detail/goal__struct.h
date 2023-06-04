// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from air_lab_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__STRUCT_H_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'type'
// Member 'object'
// Member 'destination'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Goal in the package air_lab_interfaces.
typedef struct air_lab_interfaces__msg__Goal
{
  rosidl_runtime_c__String type;
  rosidl_runtime_c__String object;
  rosidl_runtime_c__String destination;
} air_lab_interfaces__msg__Goal;

// Struct for a sequence of air_lab_interfaces__msg__Goal.
typedef struct air_lab_interfaces__msg__Goal__Sequence
{
  air_lab_interfaces__msg__Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} air_lab_interfaces__msg__Goal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__STRUCT_H_
