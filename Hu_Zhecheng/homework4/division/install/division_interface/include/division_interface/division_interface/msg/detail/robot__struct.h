// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from division_interface:msg/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__MSG__DETAIL__ROBOT__STRUCT_H_
#define DIVISION_INTERFACE__MSG__DETAIL__ROBOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Robot in the package division_interface.
typedef struct division_interface__msg__Robot
{
  int64_t num1;
  int64_t num2;
} division_interface__msg__Robot;

// Struct for a sequence of division_interface__msg__Robot.
typedef struct division_interface__msg__Robot__Sequence
{
  division_interface__msg__Robot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} division_interface__msg__Robot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DIVISION_INTERFACE__MSG__DETAIL__ROBOT__STRUCT_H_
