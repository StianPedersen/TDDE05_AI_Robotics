// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "air_lab_interfaces/msg/detail/goals_request__rosidl_typesupport_introspection_c.h"
#include "air_lab_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "air_lab_interfaces/msg/detail/goals_request__functions.h"
#include "air_lab_interfaces/msg/detail/goals_request__struct.h"


// Include directives for member types
// Member `goals`
#include "air_lab_interfaces/msg/goal.h"
// Member `goals`
#include "air_lab_interfaces/msg/detail/goal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  air_lab_interfaces__msg__GoalsRequest__init(message_memory);
}

void GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_fini_function(void * message_memory)
{
  air_lab_interfaces__msg__GoalsRequest__fini(message_memory);
}

size_t GoalsRequest__rosidl_typesupport_introspection_c__size_function__Goal__goals(
  const void * untyped_member)
{
  const air_lab_interfaces__msg__Goal__Sequence * member =
    (const air_lab_interfaces__msg__Goal__Sequence *)(untyped_member);
  return member->size;
}

const void * GoalsRequest__rosidl_typesupport_introspection_c__get_const_function__Goal__goals(
  const void * untyped_member, size_t index)
{
  const air_lab_interfaces__msg__Goal__Sequence * member =
    (const air_lab_interfaces__msg__Goal__Sequence *)(untyped_member);
  return &member->data[index];
}

void * GoalsRequest__rosidl_typesupport_introspection_c__get_function__Goal__goals(
  void * untyped_member, size_t index)
{
  air_lab_interfaces__msg__Goal__Sequence * member =
    (air_lab_interfaces__msg__Goal__Sequence *)(untyped_member);
  return &member->data[index];
}

bool GoalsRequest__rosidl_typesupport_introspection_c__resize_function__Goal__goals(
  void * untyped_member, size_t size)
{
  air_lab_interfaces__msg__Goal__Sequence * member =
    (air_lab_interfaces__msg__Goal__Sequence *)(untyped_member);
  air_lab_interfaces__msg__Goal__Sequence__fini(member);
  return air_lab_interfaces__msg__Goal__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_member_array[1] = {
  {
    "goals",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces__msg__GoalsRequest, goals),  // bytes offset in struct
    NULL,  // default value
    GoalsRequest__rosidl_typesupport_introspection_c__size_function__Goal__goals,  // size() function pointer
    GoalsRequest__rosidl_typesupport_introspection_c__get_const_function__Goal__goals,  // get_const(index) function pointer
    GoalsRequest__rosidl_typesupport_introspection_c__get_function__Goal__goals,  // get(index) function pointer
    GoalsRequest__rosidl_typesupport_introspection_c__resize_function__Goal__goals  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_members = {
  "air_lab_interfaces__msg",  // message namespace
  "GoalsRequest",  // message name
  1,  // number of fields
  sizeof(air_lab_interfaces__msg__GoalsRequest),
  GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_member_array,  // message members
  GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_init_function,  // function to initialize message memory (memory has to be allocated)
  GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_type_support_handle = {
  0,
  &GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_air_lab_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, msg, GoalsRequest)() {
  GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, msg, Goal)();
  if (!GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_type_support_handle.typesupport_identifier) {
    GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GoalsRequest__rosidl_typesupport_introspection_c__GoalsRequest_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
