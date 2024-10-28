// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/ModulusDivision.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ModulusDivision in the package custom_interfaces.
typedef struct custom_interfaces__srv__ModulusDivision_Request
{
  /// 被除数
  int64_t dividend;
  /// 除数
  int64_t divisor;
} custom_interfaces__srv__ModulusDivision_Request;

// Struct for a sequence of custom_interfaces__srv__ModulusDivision_Request.
typedef struct custom_interfaces__srv__ModulusDivision_Request__Sequence
{
  custom_interfaces__srv__ModulusDivision_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__ModulusDivision_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ModulusDivision in the package custom_interfaces.
typedef struct custom_interfaces__srv__ModulusDivision_Response
{
  /// 商
  int64_t quotient;
  /// 余数
  int64_t remainder;
} custom_interfaces__srv__ModulusDivision_Response;

// Struct for a sequence of custom_interfaces__srv__ModulusDivision_Response.
typedef struct custom_interfaces__srv__ModulusDivision_Response__Sequence
{
  custom_interfaces__srv__ModulusDivision_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__ModulusDivision_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__STRUCT_H_
