// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from division_interface:msg/Robot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "division_interface/msg/detail/robot__rosidl_typesupport_introspection_c.h"
#include "division_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "division_interface/msg/detail/robot__functions.h"
#include "division_interface/msg/detail/robot__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  division_interface__msg__Robot__init(message_memory);
}

void division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_fini_function(void * message_memory)
{
  division_interface__msg__Robot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_member_array[2] = {
  {
    "num1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interface__msg__Robot, num1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interface__msg__Robot, num2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_members = {
  "division_interface__msg",  // message namespace
  "Robot",  // message name
  2,  // number of fields
  sizeof(division_interface__msg__Robot),
  division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_member_array,  // message members
  division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_init_function,  // function to initialize message memory (memory has to be allocated)
  division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_type_support_handle = {
  0,
  &division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_division_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, division_interface, msg, Robot)() {
  if (!division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_type_support_handle.typesupport_identifier) {
    division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &division_interface__msg__Robot__rosidl_typesupport_introspection_c__Robot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
