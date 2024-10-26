// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from divide_interface:srv/Divide.idl
// generated code does not contain a copyright notice

#ifndef DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__STRUCT_H_
#define DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Divide in the package divide_interface.
typedef struct divide_interface__srv__Divide_Request
{
  int64_t dividend;
  int64_t divisor;
} divide_interface__srv__Divide_Request;

// Struct for a sequence of divide_interface__srv__Divide_Request.
typedef struct divide_interface__srv__Divide_Request__Sequence
{
  divide_interface__srv__Divide_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} divide_interface__srv__Divide_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Divide in the package divide_interface.
typedef struct divide_interface__srv__Divide_Response
{
  int64_t quotient;
  int64_t remainder;
} divide_interface__srv__Divide_Response;

// Struct for a sequence of divide_interface__srv__Divide_Response.
typedef struct divide_interface__srv__Divide_Response__Sequence
{
  divide_interface__srv__Divide_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} divide_interface__srv__Divide_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__STRUCT_H_
