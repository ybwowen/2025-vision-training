// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from action_interfaces:action/MoveRobot.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__MOVE_ROBOT__FUNCTIONS_H_
#define ACTION_INTERFACES__ACTION__DETAIL__MOVE_ROBOT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "action_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "action_interfaces/action/detail/move_robot__struct.h"

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_Goal
 * )) before or use
 * action_interfaces__action__MoveRobot_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Goal__init(action_interfaces__action__MoveRobot_Goal * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Goal__fini(action_interfaces__action__MoveRobot_Goal * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_Goal *
action_interfaces__action__MoveRobot_Goal__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Goal__destroy(action_interfaces__action__MoveRobot_Goal * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Goal__are_equal(const action_interfaces__action__MoveRobot_Goal * lhs, const action_interfaces__action__MoveRobot_Goal * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Goal__copy(
  const action_interfaces__action__MoveRobot_Goal * input,
  action_interfaces__action__MoveRobot_Goal * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Goal__Sequence__init(action_interfaces__action__MoveRobot_Goal__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Goal__Sequence__fini(action_interfaces__action__MoveRobot_Goal__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_Goal__Sequence *
action_interfaces__action__MoveRobot_Goal__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Goal__Sequence__destroy(action_interfaces__action__MoveRobot_Goal__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Goal__Sequence__are_equal(const action_interfaces__action__MoveRobot_Goal__Sequence * lhs, const action_interfaces__action__MoveRobot_Goal__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Goal__Sequence__copy(
  const action_interfaces__action__MoveRobot_Goal__Sequence * input,
  action_interfaces__action__MoveRobot_Goal__Sequence * output);

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_Result
 * )) before or use
 * action_interfaces__action__MoveRobot_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Result__init(action_interfaces__action__MoveRobot_Result * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Result__fini(action_interfaces__action__MoveRobot_Result * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_Result *
action_interfaces__action__MoveRobot_Result__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Result__destroy(action_interfaces__action__MoveRobot_Result * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Result__are_equal(const action_interfaces__action__MoveRobot_Result * lhs, const action_interfaces__action__MoveRobot_Result * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Result__copy(
  const action_interfaces__action__MoveRobot_Result * input,
  action_interfaces__action__MoveRobot_Result * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Result__Sequence__init(action_interfaces__action__MoveRobot_Result__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Result__Sequence__fini(action_interfaces__action__MoveRobot_Result__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_Result__Sequence *
action_interfaces__action__MoveRobot_Result__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Result__Sequence__destroy(action_interfaces__action__MoveRobot_Result__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Result__Sequence__are_equal(const action_interfaces__action__MoveRobot_Result__Sequence * lhs, const action_interfaces__action__MoveRobot_Result__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Result__Sequence__copy(
  const action_interfaces__action__MoveRobot_Result__Sequence * input,
  action_interfaces__action__MoveRobot_Result__Sequence * output);

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_Feedback
 * )) before or use
 * action_interfaces__action__MoveRobot_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Feedback__init(action_interfaces__action__MoveRobot_Feedback * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Feedback__fini(action_interfaces__action__MoveRobot_Feedback * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_Feedback *
action_interfaces__action__MoveRobot_Feedback__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Feedback__destroy(action_interfaces__action__MoveRobot_Feedback * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Feedback__are_equal(const action_interfaces__action__MoveRobot_Feedback * lhs, const action_interfaces__action__MoveRobot_Feedback * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Feedback__copy(
  const action_interfaces__action__MoveRobot_Feedback * input,
  action_interfaces__action__MoveRobot_Feedback * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Feedback__Sequence__init(action_interfaces__action__MoveRobot_Feedback__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Feedback__Sequence__fini(action_interfaces__action__MoveRobot_Feedback__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_Feedback__Sequence *
action_interfaces__action__MoveRobot_Feedback__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_Feedback__Sequence__destroy(action_interfaces__action__MoveRobot_Feedback__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Feedback__Sequence__are_equal(const action_interfaces__action__MoveRobot_Feedback__Sequence * lhs, const action_interfaces__action__MoveRobot_Feedback__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_Feedback__Sequence__copy(
  const action_interfaces__action__MoveRobot_Feedback__Sequence * input,
  action_interfaces__action__MoveRobot_Feedback__Sequence * output);

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_SendGoal_Request
 * )) before or use
 * action_interfaces__action__MoveRobot_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Request__init(action_interfaces__action__MoveRobot_SendGoal_Request * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Request__fini(action_interfaces__action__MoveRobot_SendGoal_Request * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_SendGoal_Request *
action_interfaces__action__MoveRobot_SendGoal_Request__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Request__destroy(action_interfaces__action__MoveRobot_SendGoal_Request * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Request__are_equal(const action_interfaces__action__MoveRobot_SendGoal_Request * lhs, const action_interfaces__action__MoveRobot_SendGoal_Request * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Request__copy(
  const action_interfaces__action__MoveRobot_SendGoal_Request * input,
  action_interfaces__action__MoveRobot_SendGoal_Request * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__init(action_interfaces__action__MoveRobot_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__fini(action_interfaces__action__MoveRobot_SendGoal_Request__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_SendGoal_Request__Sequence *
action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__destroy(action_interfaces__action__MoveRobot_SendGoal_Request__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__are_equal(const action_interfaces__action__MoveRobot_SendGoal_Request__Sequence * lhs, const action_interfaces__action__MoveRobot_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Request__Sequence__copy(
  const action_interfaces__action__MoveRobot_SendGoal_Request__Sequence * input,
  action_interfaces__action__MoveRobot_SendGoal_Request__Sequence * output);

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_SendGoal_Response
 * )) before or use
 * action_interfaces__action__MoveRobot_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Response__init(action_interfaces__action__MoveRobot_SendGoal_Response * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Response__fini(action_interfaces__action__MoveRobot_SendGoal_Response * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_SendGoal_Response *
action_interfaces__action__MoveRobot_SendGoal_Response__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Response__destroy(action_interfaces__action__MoveRobot_SendGoal_Response * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Response__are_equal(const action_interfaces__action__MoveRobot_SendGoal_Response * lhs, const action_interfaces__action__MoveRobot_SendGoal_Response * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Response__copy(
  const action_interfaces__action__MoveRobot_SendGoal_Response * input,
  action_interfaces__action__MoveRobot_SendGoal_Response * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__init(action_interfaces__action__MoveRobot_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__fini(action_interfaces__action__MoveRobot_SendGoal_Response__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_SendGoal_Response__Sequence *
action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__destroy(action_interfaces__action__MoveRobot_SendGoal_Response__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__are_equal(const action_interfaces__action__MoveRobot_SendGoal_Response__Sequence * lhs, const action_interfaces__action__MoveRobot_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_SendGoal_Response__Sequence__copy(
  const action_interfaces__action__MoveRobot_SendGoal_Response__Sequence * input,
  action_interfaces__action__MoveRobot_SendGoal_Response__Sequence * output);

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_GetResult_Request
 * )) before or use
 * action_interfaces__action__MoveRobot_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Request__init(action_interfaces__action__MoveRobot_GetResult_Request * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Request__fini(action_interfaces__action__MoveRobot_GetResult_Request * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_GetResult_Request *
action_interfaces__action__MoveRobot_GetResult_Request__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Request__destroy(action_interfaces__action__MoveRobot_GetResult_Request * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Request__are_equal(const action_interfaces__action__MoveRobot_GetResult_Request * lhs, const action_interfaces__action__MoveRobot_GetResult_Request * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Request__copy(
  const action_interfaces__action__MoveRobot_GetResult_Request * input,
  action_interfaces__action__MoveRobot_GetResult_Request * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Request__Sequence__init(action_interfaces__action__MoveRobot_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Request__Sequence__fini(action_interfaces__action__MoveRobot_GetResult_Request__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_GetResult_Request__Sequence *
action_interfaces__action__MoveRobot_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Request__Sequence__destroy(action_interfaces__action__MoveRobot_GetResult_Request__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Request__Sequence__are_equal(const action_interfaces__action__MoveRobot_GetResult_Request__Sequence * lhs, const action_interfaces__action__MoveRobot_GetResult_Request__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Request__Sequence__copy(
  const action_interfaces__action__MoveRobot_GetResult_Request__Sequence * input,
  action_interfaces__action__MoveRobot_GetResult_Request__Sequence * output);

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_GetResult_Response
 * )) before or use
 * action_interfaces__action__MoveRobot_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Response__init(action_interfaces__action__MoveRobot_GetResult_Response * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Response__fini(action_interfaces__action__MoveRobot_GetResult_Response * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_GetResult_Response *
action_interfaces__action__MoveRobot_GetResult_Response__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Response__destroy(action_interfaces__action__MoveRobot_GetResult_Response * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Response__are_equal(const action_interfaces__action__MoveRobot_GetResult_Response * lhs, const action_interfaces__action__MoveRobot_GetResult_Response * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Response__copy(
  const action_interfaces__action__MoveRobot_GetResult_Response * input,
  action_interfaces__action__MoveRobot_GetResult_Response * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Response__Sequence__init(action_interfaces__action__MoveRobot_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Response__Sequence__fini(action_interfaces__action__MoveRobot_GetResult_Response__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_GetResult_Response__Sequence *
action_interfaces__action__MoveRobot_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_GetResult_Response__Sequence__destroy(action_interfaces__action__MoveRobot_GetResult_Response__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Response__Sequence__are_equal(const action_interfaces__action__MoveRobot_GetResult_Response__Sequence * lhs, const action_interfaces__action__MoveRobot_GetResult_Response__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_GetResult_Response__Sequence__copy(
  const action_interfaces__action__MoveRobot_GetResult_Response__Sequence * input,
  action_interfaces__action__MoveRobot_GetResult_Response__Sequence * output);

/// Initialize action/MoveRobot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * action_interfaces__action__MoveRobot_FeedbackMessage
 * )) before or use
 * action_interfaces__action__MoveRobot_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_FeedbackMessage__init(action_interfaces__action__MoveRobot_FeedbackMessage * msg);

/// Finalize action/MoveRobot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_FeedbackMessage__fini(action_interfaces__action__MoveRobot_FeedbackMessage * msg);

/// Create action/MoveRobot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * action_interfaces__action__MoveRobot_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_FeedbackMessage *
action_interfaces__action__MoveRobot_FeedbackMessage__create();

/// Destroy action/MoveRobot message.
/**
 * It calls
 * action_interfaces__action__MoveRobot_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_FeedbackMessage__destroy(action_interfaces__action__MoveRobot_FeedbackMessage * msg);

/// Check for action/MoveRobot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_FeedbackMessage__are_equal(const action_interfaces__action__MoveRobot_FeedbackMessage * lhs, const action_interfaces__action__MoveRobot_FeedbackMessage * rhs);

/// Copy a action/MoveRobot message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_FeedbackMessage__copy(
  const action_interfaces__action__MoveRobot_FeedbackMessage * input,
  action_interfaces__action__MoveRobot_FeedbackMessage * output);

/// Initialize array of action/MoveRobot messages.
/**
 * It allocates the memory for the number of elements and calls
 * action_interfaces__action__MoveRobot_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__init(action_interfaces__action__MoveRobot_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__fini(action_interfaces__action__MoveRobot_FeedbackMessage__Sequence * array);

/// Create array of action/MoveRobot messages.
/**
 * It allocates the memory for the array and calls
 * action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
action_interfaces__action__MoveRobot_FeedbackMessage__Sequence *
action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/MoveRobot messages.
/**
 * It calls
 * action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
void
action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__destroy(action_interfaces__action__MoveRobot_FeedbackMessage__Sequence * array);

/// Check for action/MoveRobot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__are_equal(const action_interfaces__action__MoveRobot_FeedbackMessage__Sequence * lhs, const action_interfaces__action__MoveRobot_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/MoveRobot messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_action_interfaces
bool
action_interfaces__action__MoveRobot_FeedbackMessage__Sequence__copy(
  const action_interfaces__action__MoveRobot_FeedbackMessage__Sequence * input,
  action_interfaces__action__MoveRobot_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__ACTION__DETAIL__MOVE_ROBOT__FUNCTIONS_H_
