// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from divide_interface:srv/Divide.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "divide_interface/srv/detail/divide__rosidl_typesupport_introspection_c.h"
#include "divide_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "divide_interface/srv/detail/divide__functions.h"
#include "divide_interface/srv/detail/divide__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  divide_interface__srv__Divide_Request__init(message_memory);
}

void divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_fini_function(void * message_memory)
{
  divide_interface__srv__Divide_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_member_array[2] = {
  {
    "dividend",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(divide_interface__srv__Divide_Request, dividend),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "divisor",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(divide_interface__srv__Divide_Request, divisor),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_members = {
  "divide_interface__srv",  // message namespace
  "Divide_Request",  // message name
  2,  // number of fields
  sizeof(divide_interface__srv__Divide_Request),
  divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_member_array,  // message members
  divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_type_support_handle = {
  0,
  &divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_divide_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, divide_interface, srv, Divide_Request)() {
  if (!divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_type_support_handle.typesupport_identifier) {
    divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &divide_interface__srv__Divide_Request__rosidl_typesupport_introspection_c__Divide_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "divide_interface/srv/detail/divide__rosidl_typesupport_introspection_c.h"
// already included above
// #include "divide_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "divide_interface/srv/detail/divide__functions.h"
// already included above
// #include "divide_interface/srv/detail/divide__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  divide_interface__srv__Divide_Response__init(message_memory);
}

void divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_fini_function(void * message_memory)
{
  divide_interface__srv__Divide_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_member_array[2] = {
  {
    "quotient",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(divide_interface__srv__Divide_Response, quotient),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "remainder",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(divide_interface__srv__Divide_Response, remainder),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_members = {
  "divide_interface__srv",  // message namespace
  "Divide_Response",  // message name
  2,  // number of fields
  sizeof(divide_interface__srv__Divide_Response),
  divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_member_array,  // message members
  divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_type_support_handle = {
  0,
  &divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_divide_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, divide_interface, srv, Divide_Response)() {
  if (!divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_type_support_handle.typesupport_identifier) {
    divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &divide_interface__srv__Divide_Response__rosidl_typesupport_introspection_c__Divide_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "divide_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "divide_interface/srv/detail/divide__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_service_members = {
  "divide_interface__srv",  // service namespace
  "Divide",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_Request_message_type_support_handle,
  NULL  // response message
  // divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_Response_message_type_support_handle
};

static rosidl_service_type_support_t divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_service_type_support_handle = {
  0,
  &divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, divide_interface, srv, Divide_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, divide_interface, srv, Divide_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_divide_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, divide_interface, srv, Divide)() {
  if (!divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_service_type_support_handle.typesupport_identifier) {
    divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, divide_interface, srv, Divide_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, divide_interface, srv, Divide_Response)()->data;
  }

  return &divide_interface__srv__detail__divide__rosidl_typesupport_introspection_c__Divide_service_type_support_handle;
}
