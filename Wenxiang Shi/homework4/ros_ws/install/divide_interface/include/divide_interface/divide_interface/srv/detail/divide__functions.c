// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from divide_interface:srv/Divide.idl
// generated code does not contain a copyright notice
#include "divide_interface/srv/detail/divide__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
divide_interface__srv__Divide_Request__init(divide_interface__srv__Divide_Request * msg)
{
  if (!msg) {
    return false;
  }
  // dividend
  // divisor
  return true;
}

void
divide_interface__srv__Divide_Request__fini(divide_interface__srv__Divide_Request * msg)
{
  if (!msg) {
    return;
  }
  // dividend
  // divisor
}

bool
divide_interface__srv__Divide_Request__are_equal(const divide_interface__srv__Divide_Request * lhs, const divide_interface__srv__Divide_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // dividend
  if (lhs->dividend != rhs->dividend) {
    return false;
  }
  // divisor
  if (lhs->divisor != rhs->divisor) {
    return false;
  }
  return true;
}

bool
divide_interface__srv__Divide_Request__copy(
  const divide_interface__srv__Divide_Request * input,
  divide_interface__srv__Divide_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // dividend
  output->dividend = input->dividend;
  // divisor
  output->divisor = input->divisor;
  return true;
}

divide_interface__srv__Divide_Request *
divide_interface__srv__Divide_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  divide_interface__srv__Divide_Request * msg = (divide_interface__srv__Divide_Request *)allocator.allocate(sizeof(divide_interface__srv__Divide_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(divide_interface__srv__Divide_Request));
  bool success = divide_interface__srv__Divide_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
divide_interface__srv__Divide_Request__destroy(divide_interface__srv__Divide_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    divide_interface__srv__Divide_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
divide_interface__srv__Divide_Request__Sequence__init(divide_interface__srv__Divide_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  divide_interface__srv__Divide_Request * data = NULL;

  if (size) {
    data = (divide_interface__srv__Divide_Request *)allocator.zero_allocate(size, sizeof(divide_interface__srv__Divide_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = divide_interface__srv__Divide_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        divide_interface__srv__Divide_Request__fini(&data[i - 1]);
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
divide_interface__srv__Divide_Request__Sequence__fini(divide_interface__srv__Divide_Request__Sequence * array)
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
      divide_interface__srv__Divide_Request__fini(&array->data[i]);
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

divide_interface__srv__Divide_Request__Sequence *
divide_interface__srv__Divide_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  divide_interface__srv__Divide_Request__Sequence * array = (divide_interface__srv__Divide_Request__Sequence *)allocator.allocate(sizeof(divide_interface__srv__Divide_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = divide_interface__srv__Divide_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
divide_interface__srv__Divide_Request__Sequence__destroy(divide_interface__srv__Divide_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    divide_interface__srv__Divide_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
divide_interface__srv__Divide_Request__Sequence__are_equal(const divide_interface__srv__Divide_Request__Sequence * lhs, const divide_interface__srv__Divide_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!divide_interface__srv__Divide_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
divide_interface__srv__Divide_Request__Sequence__copy(
  const divide_interface__srv__Divide_Request__Sequence * input,
  divide_interface__srv__Divide_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(divide_interface__srv__Divide_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    divide_interface__srv__Divide_Request * data =
      (divide_interface__srv__Divide_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!divide_interface__srv__Divide_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          divide_interface__srv__Divide_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!divide_interface__srv__Divide_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
divide_interface__srv__Divide_Response__init(divide_interface__srv__Divide_Response * msg)
{
  if (!msg) {
    return false;
  }
  // quotient
  // remainder
  return true;
}

void
divide_interface__srv__Divide_Response__fini(divide_interface__srv__Divide_Response * msg)
{
  if (!msg) {
    return;
  }
  // quotient
  // remainder
}

bool
divide_interface__srv__Divide_Response__are_equal(const divide_interface__srv__Divide_Response * lhs, const divide_interface__srv__Divide_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // quotient
  if (lhs->quotient != rhs->quotient) {
    return false;
  }
  // remainder
  if (lhs->remainder != rhs->remainder) {
    return false;
  }
  return true;
}

bool
divide_interface__srv__Divide_Response__copy(
  const divide_interface__srv__Divide_Response * input,
  divide_interface__srv__Divide_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // quotient
  output->quotient = input->quotient;
  // remainder
  output->remainder = input->remainder;
  return true;
}

divide_interface__srv__Divide_Response *
divide_interface__srv__Divide_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  divide_interface__srv__Divide_Response * msg = (divide_interface__srv__Divide_Response *)allocator.allocate(sizeof(divide_interface__srv__Divide_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(divide_interface__srv__Divide_Response));
  bool success = divide_interface__srv__Divide_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
divide_interface__srv__Divide_Response__destroy(divide_interface__srv__Divide_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    divide_interface__srv__Divide_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
divide_interface__srv__Divide_Response__Sequence__init(divide_interface__srv__Divide_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  divide_interface__srv__Divide_Response * data = NULL;

  if (size) {
    data = (divide_interface__srv__Divide_Response *)allocator.zero_allocate(size, sizeof(divide_interface__srv__Divide_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = divide_interface__srv__Divide_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        divide_interface__srv__Divide_Response__fini(&data[i - 1]);
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
divide_interface__srv__Divide_Response__Sequence__fini(divide_interface__srv__Divide_Response__Sequence * array)
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
      divide_interface__srv__Divide_Response__fini(&array->data[i]);
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

divide_interface__srv__Divide_Response__Sequence *
divide_interface__srv__Divide_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  divide_interface__srv__Divide_Response__Sequence * array = (divide_interface__srv__Divide_Response__Sequence *)allocator.allocate(sizeof(divide_interface__srv__Divide_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = divide_interface__srv__Divide_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
divide_interface__srv__Divide_Response__Sequence__destroy(divide_interface__srv__Divide_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    divide_interface__srv__Divide_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
divide_interface__srv__Divide_Response__Sequence__are_equal(const divide_interface__srv__Divide_Response__Sequence * lhs, const divide_interface__srv__Divide_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!divide_interface__srv__Divide_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
divide_interface__srv__Divide_Response__Sequence__copy(
  const divide_interface__srv__Divide_Response__Sequence * input,
  divide_interface__srv__Divide_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(divide_interface__srv__Divide_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    divide_interface__srv__Divide_Response * data =
      (divide_interface__srv__Divide_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!divide_interface__srv__Divide_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          divide_interface__srv__Divide_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!divide_interface__srv__Divide_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
