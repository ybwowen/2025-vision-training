// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from action_demo:srv/Action.idl
// generated code does not contain a copyright notice
#include "action_demo/srv/detail/action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
action_demo__srv__Action_Request__init(action_demo__srv__Action_Request * msg)
{
  if (!msg) {
    return false;
  }
  // distance
  return true;
}

void
action_demo__srv__Action_Request__fini(action_demo__srv__Action_Request * msg)
{
  if (!msg) {
    return;
  }
  // distance
}

bool
action_demo__srv__Action_Request__are_equal(const action_demo__srv__Action_Request * lhs, const action_demo__srv__Action_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  return true;
}

bool
action_demo__srv__Action_Request__copy(
  const action_demo__srv__Action_Request * input,
  action_demo__srv__Action_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // distance
  output->distance = input->distance;
  return true;
}

action_demo__srv__Action_Request *
action_demo__srv__Action_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_demo__srv__Action_Request * msg = (action_demo__srv__Action_Request *)allocator.allocate(sizeof(action_demo__srv__Action_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__srv__Action_Request));
  bool success = action_demo__srv__Action_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_demo__srv__Action_Request__destroy(action_demo__srv__Action_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_demo__srv__Action_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_demo__srv__Action_Request__Sequence__init(action_demo__srv__Action_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_demo__srv__Action_Request * data = NULL;

  if (size) {
    data = (action_demo__srv__Action_Request *)allocator.zero_allocate(size, sizeof(action_demo__srv__Action_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__srv__Action_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__srv__Action_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__srv__Action_Request__Sequence__fini(action_demo__srv__Action_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__srv__Action_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__srv__Action_Request__Sequence *
action_demo__srv__Action_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_demo__srv__Action_Request__Sequence * array = (action_demo__srv__Action_Request__Sequence *)allocator.allocate(sizeof(action_demo__srv__Action_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_demo__srv__Action_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_demo__srv__Action_Request__Sequence__destroy(action_demo__srv__Action_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_demo__srv__Action_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_demo__srv__Action_Request__Sequence__are_equal(const action_demo__srv__Action_Request__Sequence * lhs, const action_demo__srv__Action_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__srv__Action_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__srv__Action_Request__Sequence__copy(
  const action_demo__srv__Action_Request__Sequence * input,
  action_demo__srv__Action_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__srv__Action_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_demo__srv__Action_Request * data =
      (action_demo__srv__Action_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__srv__Action_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_demo__srv__Action_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__srv__Action_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
action_demo__srv__Action_Response__init(action_demo__srv__Action_Response * msg)
{
  if (!msg) {
    return false;
  }
  // remaining_distance
  // success
  return true;
}

void
action_demo__srv__Action_Response__fini(action_demo__srv__Action_Response * msg)
{
  if (!msg) {
    return;
  }
  // remaining_distance
  // success
}

bool
action_demo__srv__Action_Response__are_equal(const action_demo__srv__Action_Response * lhs, const action_demo__srv__Action_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // remaining_distance
  if (lhs->remaining_distance != rhs->remaining_distance) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
action_demo__srv__Action_Response__copy(
  const action_demo__srv__Action_Response * input,
  action_demo__srv__Action_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // remaining_distance
  output->remaining_distance = input->remaining_distance;
  // success
  output->success = input->success;
  return true;
}

action_demo__srv__Action_Response *
action_demo__srv__Action_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_demo__srv__Action_Response * msg = (action_demo__srv__Action_Response *)allocator.allocate(sizeof(action_demo__srv__Action_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_demo__srv__Action_Response));
  bool success = action_demo__srv__Action_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_demo__srv__Action_Response__destroy(action_demo__srv__Action_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_demo__srv__Action_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_demo__srv__Action_Response__Sequence__init(action_demo__srv__Action_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_demo__srv__Action_Response * data = NULL;

  if (size) {
    data = (action_demo__srv__Action_Response *)allocator.zero_allocate(size, sizeof(action_demo__srv__Action_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_demo__srv__Action_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_demo__srv__Action_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_demo__srv__Action_Response__Sequence__fini(action_demo__srv__Action_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_demo__srv__Action_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_demo__srv__Action_Response__Sequence *
action_demo__srv__Action_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_demo__srv__Action_Response__Sequence * array = (action_demo__srv__Action_Response__Sequence *)allocator.allocate(sizeof(action_demo__srv__Action_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_demo__srv__Action_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_demo__srv__Action_Response__Sequence__destroy(action_demo__srv__Action_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_demo__srv__Action_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_demo__srv__Action_Response__Sequence__are_equal(const action_demo__srv__Action_Response__Sequence * lhs, const action_demo__srv__Action_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_demo__srv__Action_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_demo__srv__Action_Response__Sequence__copy(
  const action_demo__srv__Action_Response__Sequence * input,
  action_demo__srv__Action_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_demo__srv__Action_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_demo__srv__Action_Response * data =
      (action_demo__srv__Action_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_demo__srv__Action_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_demo__srv__Action_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_demo__srv__Action_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
