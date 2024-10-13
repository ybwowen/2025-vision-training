// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from division_interface:srv/Robot.idl
// generated code does not contain a copyright notice
#include "division_interface/srv/detail/robot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
division_interface__srv__Robot_Request__init(division_interface__srv__Robot_Request * msg)
{
  if (!msg) {
    return false;
  }
  // num1
  // num2
  return true;
}

void
division_interface__srv__Robot_Request__fini(division_interface__srv__Robot_Request * msg)
{
  if (!msg) {
    return;
  }
  // num1
  // num2
}

bool
division_interface__srv__Robot_Request__are_equal(const division_interface__srv__Robot_Request * lhs, const division_interface__srv__Robot_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // num1
  if (lhs->num1 != rhs->num1) {
    return false;
  }
  // num2
  if (lhs->num2 != rhs->num2) {
    return false;
  }
  return true;
}

bool
division_interface__srv__Robot_Request__copy(
  const division_interface__srv__Robot_Request * input,
  division_interface__srv__Robot_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // num1
  output->num1 = input->num1;
  // num2
  output->num2 = input->num2;
  return true;
}

division_interface__srv__Robot_Request *
division_interface__srv__Robot_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  division_interface__srv__Robot_Request * msg = (division_interface__srv__Robot_Request *)allocator.allocate(sizeof(division_interface__srv__Robot_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(division_interface__srv__Robot_Request));
  bool success = division_interface__srv__Robot_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
division_interface__srv__Robot_Request__destroy(division_interface__srv__Robot_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    division_interface__srv__Robot_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
division_interface__srv__Robot_Request__Sequence__init(division_interface__srv__Robot_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  division_interface__srv__Robot_Request * data = NULL;

  if (size) {
    data = (division_interface__srv__Robot_Request *)allocator.zero_allocate(size, sizeof(division_interface__srv__Robot_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = division_interface__srv__Robot_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        division_interface__srv__Robot_Request__fini(&data[i - 1]);
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
division_interface__srv__Robot_Request__Sequence__fini(division_interface__srv__Robot_Request__Sequence * array)
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
      division_interface__srv__Robot_Request__fini(&array->data[i]);
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

division_interface__srv__Robot_Request__Sequence *
division_interface__srv__Robot_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  division_interface__srv__Robot_Request__Sequence * array = (division_interface__srv__Robot_Request__Sequence *)allocator.allocate(sizeof(division_interface__srv__Robot_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = division_interface__srv__Robot_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
division_interface__srv__Robot_Request__Sequence__destroy(division_interface__srv__Robot_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    division_interface__srv__Robot_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
division_interface__srv__Robot_Request__Sequence__are_equal(const division_interface__srv__Robot_Request__Sequence * lhs, const division_interface__srv__Robot_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!division_interface__srv__Robot_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
division_interface__srv__Robot_Request__Sequence__copy(
  const division_interface__srv__Robot_Request__Sequence * input,
  division_interface__srv__Robot_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(division_interface__srv__Robot_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    division_interface__srv__Robot_Request * data =
      (division_interface__srv__Robot_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!division_interface__srv__Robot_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          division_interface__srv__Robot_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!division_interface__srv__Robot_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
division_interface__srv__Robot_Response__init(division_interface__srv__Robot_Response * msg)
{
  if (!msg) {
    return false;
  }
  // quotient
  // remainder
  return true;
}

void
division_interface__srv__Robot_Response__fini(division_interface__srv__Robot_Response * msg)
{
  if (!msg) {
    return;
  }
  // quotient
  // remainder
}

bool
division_interface__srv__Robot_Response__are_equal(const division_interface__srv__Robot_Response * lhs, const division_interface__srv__Robot_Response * rhs)
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
division_interface__srv__Robot_Response__copy(
  const division_interface__srv__Robot_Response * input,
  division_interface__srv__Robot_Response * output)
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

division_interface__srv__Robot_Response *
division_interface__srv__Robot_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  division_interface__srv__Robot_Response * msg = (division_interface__srv__Robot_Response *)allocator.allocate(sizeof(division_interface__srv__Robot_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(division_interface__srv__Robot_Response));
  bool success = division_interface__srv__Robot_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
division_interface__srv__Robot_Response__destroy(division_interface__srv__Robot_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    division_interface__srv__Robot_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
division_interface__srv__Robot_Response__Sequence__init(division_interface__srv__Robot_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  division_interface__srv__Robot_Response * data = NULL;

  if (size) {
    data = (division_interface__srv__Robot_Response *)allocator.zero_allocate(size, sizeof(division_interface__srv__Robot_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = division_interface__srv__Robot_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        division_interface__srv__Robot_Response__fini(&data[i - 1]);
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
division_interface__srv__Robot_Response__Sequence__fini(division_interface__srv__Robot_Response__Sequence * array)
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
      division_interface__srv__Robot_Response__fini(&array->data[i]);
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

division_interface__srv__Robot_Response__Sequence *
division_interface__srv__Robot_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  division_interface__srv__Robot_Response__Sequence * array = (division_interface__srv__Robot_Response__Sequence *)allocator.allocate(sizeof(division_interface__srv__Robot_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = division_interface__srv__Robot_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
division_interface__srv__Robot_Response__Sequence__destroy(division_interface__srv__Robot_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    division_interface__srv__Robot_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
division_interface__srv__Robot_Response__Sequence__are_equal(const division_interface__srv__Robot_Response__Sequence * lhs, const division_interface__srv__Robot_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!division_interface__srv__Robot_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
division_interface__srv__Robot_Response__Sequence__copy(
  const division_interface__srv__Robot_Response__Sequence * input,
  division_interface__srv__Robot_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(division_interface__srv__Robot_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    division_interface__srv__Robot_Response * data =
      (division_interface__srv__Robot_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!division_interface__srv__Robot_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          division_interface__srv__Robot_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!division_interface__srv__Robot_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
