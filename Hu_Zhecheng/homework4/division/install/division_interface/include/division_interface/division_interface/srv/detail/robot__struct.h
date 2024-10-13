// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from division_interface:srv/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__SRV__DETAIL__ROBOT__STRUCT_H_
#define DIVISION_INTERFACE__SRV__DETAIL__ROBOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Robot in the package division_interface.
typedef struct division_interface__srv__Robot_Request
{
  int64_t num1;
  int64_t num2;
} division_interface__srv__Robot_Request;

// Struct for a sequence of division_interface__srv__Robot_Request.
typedef struct division_interface__srv__Robot_Request__Sequence
{
  division_interface__srv__Robot_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} division_interface__srv__Robot_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Robot in the package division_interface.
typedef struct division_interface__srv__Robot_Response
{
  int64_t quotient;
  int64_t remainder;
} division_interface__srv__Robot_Response;

// Struct for a sequence of division_interface__srv__Robot_Response.
typedef struct division_interface__srv__Robot_Response__Sequence
{
  division_interface__srv__Robot_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} division_interface__srv__Robot_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DIVISION_INTERFACE__SRV__DETAIL__ROBOT__STRUCT_H_
