// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from division_interface:msg/Robot.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "division_interface/msg/detail/robot__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace division_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Robot_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) division_interface::msg::Robot(_init);
}

void Robot_fini_function(void * message_memory)
{
  auto typed_message = static_cast<division_interface::msg::Robot *>(message_memory);
  typed_message->~Robot();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Robot_message_member_array[2] = {
  {
    "num1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interface::msg::Robot, num1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(division_interface::msg::Robot, num2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Robot_message_members = {
  "division_interface::msg",  // message namespace
  "Robot",  // message name
  2,  // number of fields
  sizeof(division_interface::msg::Robot),
  Robot_message_member_array,  // message members
  Robot_init_function,  // function to initialize message memory (memory has to be allocated)
  Robot_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Robot_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Robot_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace division_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<division_interface::msg::Robot>()
{
  return &::division_interface::msg::rosidl_typesupport_introspection_cpp::Robot_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, division_interface, msg, Robot)() {
  return &::division_interface::msg::rosidl_typesupport_introspection_cpp::Robot_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
