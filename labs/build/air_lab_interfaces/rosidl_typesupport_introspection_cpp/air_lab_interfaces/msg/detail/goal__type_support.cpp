// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from air_lab_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "air_lab_interfaces/msg/detail/goal__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace air_lab_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Goal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) air_lab_interfaces::msg::Goal(_init);
}

void Goal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<air_lab_interfaces::msg::Goal *>(message_memory);
  typed_message->~Goal();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Goal_message_member_array[3] = {
  {
    "type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces::msg::Goal, type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "object",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces::msg::Goal, object),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "destination",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces::msg::Goal, destination),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Goal_message_members = {
  "air_lab_interfaces::msg",  // message namespace
  "Goal",  // message name
  3,  // number of fields
  sizeof(air_lab_interfaces::msg::Goal),
  Goal_message_member_array,  // message members
  Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  Goal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Goal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Goal_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace air_lab_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<air_lab_interfaces::msg::Goal>()
{
  return &::air_lab_interfaces::msg::rosidl_typesupport_introspection_cpp::Goal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, air_lab_interfaces, msg, Goal)() {
  return &::air_lab_interfaces::msg::rosidl_typesupport_introspection_cpp::Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
