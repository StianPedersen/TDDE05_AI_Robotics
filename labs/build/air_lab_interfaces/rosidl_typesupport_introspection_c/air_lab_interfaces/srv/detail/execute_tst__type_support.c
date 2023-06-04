// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from air_lab_interfaces:srv/ExecuteTst.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "air_lab_interfaces/srv/detail/execute_tst__rosidl_typesupport_introspection_c.h"
#include "air_lab_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "air_lab_interfaces/srv/detail/execute_tst__functions.h"
#include "air_lab_interfaces/srv/detail/execute_tst__struct.h"


// Include directives for member types
// Member `tst_file`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  air_lab_interfaces__srv__ExecuteTst_Request__init(message_memory);
}

void ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_fini_function(void * message_memory)
{
  air_lab_interfaces__srv__ExecuteTst_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_member_array[1] = {
  {
    "tst_file",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces__srv__ExecuteTst_Request, tst_file),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_members = {
  "air_lab_interfaces__srv",  // message namespace
  "ExecuteTst_Request",  // message name
  1,  // number of fields
  sizeof(air_lab_interfaces__srv__ExecuteTst_Request),
  ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_member_array,  // message members
  ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_type_support_handle = {
  0,
  &ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_air_lab_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, srv, ExecuteTst_Request)() {
  if (!ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_type_support_handle.typesupport_identifier) {
    ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ExecuteTst_Request__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "air_lab_interfaces/srv/detail/execute_tst__rosidl_typesupport_introspection_c.h"
// already included above
// #include "air_lab_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "air_lab_interfaces/srv/detail/execute_tst__functions.h"
// already included above
// #include "air_lab_interfaces/srv/detail/execute_tst__struct.h"


// Include directives for member types
// Member `my_error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  air_lab_interfaces__srv__ExecuteTst_Response__init(message_memory);
}

void ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_fini_function(void * message_memory)
{
  air_lab_interfaces__srv__ExecuteTst_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces__srv__ExecuteTst_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "my_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(air_lab_interfaces__srv__ExecuteTst_Response, my_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_members = {
  "air_lab_interfaces__srv",  // message namespace
  "ExecuteTst_Response",  // message name
  2,  // number of fields
  sizeof(air_lab_interfaces__srv__ExecuteTst_Response),
  ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_member_array,  // message members
  ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_type_support_handle = {
  0,
  &ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_air_lab_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, srv, ExecuteTst_Response)() {
  if (!ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_type_support_handle.typesupport_identifier) {
    ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ExecuteTst_Response__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "air_lab_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "air_lab_interfaces/srv/detail/execute_tst__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_service_members = {
  "air_lab_interfaces__srv",  // service namespace
  "ExecuteTst",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_Request_message_type_support_handle,
  NULL  // response message
  // air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_Response_message_type_support_handle
};

static rosidl_service_type_support_t air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_service_type_support_handle = {
  0,
  &air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, srv, ExecuteTst_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, srv, ExecuteTst_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_air_lab_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, srv, ExecuteTst)() {
  if (!air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_service_type_support_handle.typesupport_identifier) {
    air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, srv, ExecuteTst_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, air_lab_interfaces, srv, ExecuteTst_Response)()->data;
  }

  return &air_lab_interfaces__srv__detail__execute_tst__rosidl_typesupport_introspection_c__ExecuteTst_service_type_support_handle;
}
