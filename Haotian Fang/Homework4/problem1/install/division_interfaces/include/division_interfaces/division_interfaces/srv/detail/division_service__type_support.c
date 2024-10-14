// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from division_interfaces:srv/DivisionService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "division_interfaces/srv/detail/division_service__rosidl_typesupport_introspection_c.h"
#include "division_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "division_interfaces/srv/detail/division_service__functions.h"
#include "division_interfaces/srv/detail/division_service__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  division_interfaces__srv__DivisionService_Request__init(message_memory);
}

void division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_fini_function(void * message_memory)
{
  division_interfaces__srv__DivisionService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_member_array[2] = {
  {
    "dividend",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interfaces__srv__DivisionService_Request, dividend),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interfaces__srv__DivisionService_Request, divisor),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_members = {
  "division_interfaces__srv",  // message namespace
  "DivisionService_Request",  // message name
  2,  // number of fields
  sizeof(division_interfaces__srv__DivisionService_Request),
  division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_member_array,  // message members
  division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_type_support_handle = {
  0,
  &division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_division_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interfaces, srv, DivisionService_Request)() {
  if (!division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_type_support_handle.typesupport_identifier) {
    division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &division_interfaces__srv__DivisionService_Request__rosidl_typesupport_introspection_c__DivisionService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "division_interfaces/srv/detail/division_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "division_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "division_interfaces/srv/detail/division_service__functions.h"
// already included above
// #include "division_interfaces/srv/detail/division_service__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  division_interfaces__srv__DivisionService_Response__init(message_memory);
}

void division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_fini_function(void * message_memory)
{
  division_interfaces__srv__DivisionService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_member_array[2] = {
  {
    "quotient",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interfaces__srv__DivisionService_Response, quotient),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interfaces__srv__DivisionService_Response, remainder),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_members = {
  "division_interfaces__srv",  // message namespace
  "DivisionService_Response",  // message name
  2,  // number of fields
  sizeof(division_interfaces__srv__DivisionService_Response),
  division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_member_array,  // message members
  division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_type_support_handle = {
  0,
  &division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_division_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interfaces, srv, DivisionService_Response)() {
  if (!division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_type_support_handle.typesupport_identifier) {
    division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &division_interfaces__srv__DivisionService_Response__rosidl_typesupport_introspection_c__DivisionService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "division_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "division_interfaces/srv/detail/division_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_service_members = {
  "division_interfaces__srv",  // service namespace
  "DivisionService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_Request_message_type_support_handle,
  NULL  // response message
  // division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_Response_message_type_support_handle
};

static rosidl_service_type_support_t division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_service_type_support_handle = {
  0,
  &division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interfaces, srv, DivisionService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interfaces, srv, DivisionService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_division_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interfaces, srv, DivisionService)() {
  if (!division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_service_type_support_handle.typesupport_identifier) {
    division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interfaces, srv, DivisionService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interfaces, srv, DivisionService_Response)()->data;
  }

  return &division_interfaces__srv__detail__division_service__rosidl_typesupport_introspection_c__DivisionService_service_type_support_handle;
}
