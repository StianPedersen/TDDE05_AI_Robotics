// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "air_lab_interfaces/msg/detail/goals_request__struct.hpp"
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

void GoalsRequest_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) air_lab_interfaces::msg::GoalsRequest(_init);
}

void GoalsRequest_fini_function(void * message_memory)
{
  auto typed_message = static_cast<air_lab_interfaces::msg::GoalsRequest *>(message_memory);
  typed_message->~GoalsRequest();
}

size_t size_function__GoalsRequest__goals(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<air_lab_interfaces::msg::Goal> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GoalsRequest__goals(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<air_lab_interfaces::msg::Goal> *>(untyped_member);
  return &member[index];
}

void * get_function__GoalsRequest__goals(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<air_lab_interfaces::msg::Goal> *>(untyped_member);
  return &member[index];
}

void resize_function__GoalsRequest__goals(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<air_lab_interfaces::msg::Goal> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GoalsRequest_message_member_array[1] = {
  {
    "goals",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<air_lab_interfaces::msg::Goal>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces::msg::GoalsRequest, goals),  // bytes offset in struct
    nullptr,  // default value
    size_function__GoalsRequest__goals,  // size() function pointer
    get_const_function__GoalsRequest__goals,  // get_const(index) function pointer
    get_function__GoalsRequest__goals,  // get(index) function pointer
    resize_function__GoalsRequest__goals  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GoalsRequest_message_members = {
  "air_lab_interfaces::msg",  // message namespace
  "GoalsRequest",  // message name
  1,  // number of fields
  sizeof(air_lab_interfaces::msg::GoalsRequest),
  GoalsRequest_message_member_array,  // message members
  GoalsRequest_init_function,  // function to initialize message memory (memory has to be allocated)
  GoalsRequest_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GoalsRequest_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GoalsRequest_message_members,
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
get_message_type_support_handle<air_lab_interfaces::msg::GoalsRequest>()
{
  return &::air_lab_interfaces::msg::rosidl_typesupport_introspection_cpp::GoalsRequest_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, air_lab_interfaces, msg, GoalsRequest)() {
  return &::air_lab_interfaces::msg::rosidl_typesupport_introspection_cpp::GoalsRequest_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
