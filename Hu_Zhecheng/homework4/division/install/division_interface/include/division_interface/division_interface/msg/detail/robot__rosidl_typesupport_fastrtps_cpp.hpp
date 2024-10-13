// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from division_interface:msg/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__MSG__DETAIL__ROBOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DIVISION_INTERFACE__MSG__DETAIL__ROBOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "division_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "division_interface/msg/detail/robot__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace division_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_division_interface
cdr_serialize(
  const division_interface::msg::Robot & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_division_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  division_interface::msg::Robot & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_division_interface
get_serialized_size(
  const division_interface::msg::Robot & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_division_interface
max_serialized_size_Robot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace division_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_division_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, division_interface, msg, Robot)();

#ifdef __cplusplus
}
#endif

#endif  // DIVISION_INTERFACE__MSG__DETAIL__ROBOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
