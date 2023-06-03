// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from air_lab_interfaces:srv/ExecuteTst.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__STRUCT_H_
#define AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tst_file'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/ExecuteTst in the package air_lab_interfaces.
typedef struct air_lab_interfaces__srv__ExecuteTst_Request
{
  rosidl_runtime_c__String tst_file;
} air_lab_interfaces__srv__ExecuteTst_Request;

// Struct for a sequence of air_lab_interfaces__srv__ExecuteTst_Request.
typedef struct air_lab_interfaces__srv__ExecuteTst_Request__Sequence
{
  air_lab_interfaces__srv__ExecuteTst_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} air_lab_interfaces__srv__ExecuteTst_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'my_error'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/ExecuteTst in the package air_lab_interfaces.
typedef struct air_lab_interfaces__srv__ExecuteTst_Response
{
  bool success;
  rosidl_runtime_c__String my_error;
} air_lab_interfaces__srv__ExecuteTst_Response;

// Struct for a sequence of air_lab_interfaces__srv__ExecuteTst_Response.
typedef struct air_lab_interfaces__srv__ExecuteTst_Response__Sequence
{
  air_lab_interfaces__srv__ExecuteTst_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} air_lab_interfaces__srv__ExecuteTst_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__STRUCT_H_
