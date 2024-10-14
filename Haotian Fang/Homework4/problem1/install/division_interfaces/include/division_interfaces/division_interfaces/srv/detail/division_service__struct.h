// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from division_interfaces:srv/DivisionService.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__STRUCT_H_
#define DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DivisionService in the package division_interfaces.
typedef struct division_interfaces__srv__DivisionService_Request
{
  int64_t dividend;
  int64_t divisor;
} division_interfaces__srv__DivisionService_Request;

// Struct for a sequence of division_interfaces__srv__DivisionService_Request.
typedef struct division_interfaces__srv__DivisionService_Request__Sequence
{
  division_interfaces__srv__DivisionService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} division_interfaces__srv__DivisionService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/DivisionService in the package division_interfaces.
typedef struct division_interfaces__srv__DivisionService_Response
{
  int64_t quotient;
  int64_t remainder;
} division_interfaces__srv__DivisionService_Response;

// Struct for a sequence of division_interfaces__srv__DivisionService_Response.
typedef struct division_interfaces__srv__DivisionService_Response__Sequence
{
  division_interfaces__srv__DivisionService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} division_interfaces__srv__DivisionService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__STRUCT_H_
