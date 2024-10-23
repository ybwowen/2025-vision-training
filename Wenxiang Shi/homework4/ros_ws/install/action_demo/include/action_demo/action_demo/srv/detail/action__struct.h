// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_demo:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef ACTION_DEMO__SRV__DETAIL__ACTION__STRUCT_H_
#define ACTION_DEMO__SRV__DETAIL__ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Action in the package action_demo.
typedef struct action_demo__srv__Action_Request
{
  double distance;
} action_demo__srv__Action_Request;

// Struct for a sequence of action_demo__srv__Action_Request.
typedef struct action_demo__srv__Action_Request__Sequence
{
  action_demo__srv__Action_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_demo__srv__Action_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Action in the package action_demo.
typedef struct action_demo__srv__Action_Response
{
  double remaining_distance;
  bool success;
} action_demo__srv__Action_Response;

// Struct for a sequence of action_demo__srv__Action_Response.
typedef struct action_demo__srv__Action_Response__Sequence
{
  action_demo__srv__Action_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_demo__srv__Action_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_DEMO__SRV__DETAIL__ACTION__STRUCT_H_
