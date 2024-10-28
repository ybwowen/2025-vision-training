// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_interfaces:srv/ModulusDivision.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_interfaces/srv/detail/modulus_division__struct.h"
#include "custom_interfaces/srv/detail/modulus_division__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_interfaces__srv__modulus_division__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_interfaces.srv._modulus_division.ModulusDivision_Request", full_classname_dest, 63) == 0);
  }
  custom_interfaces__srv__ModulusDivision_Request * ros_message = _ros_message;
  {  // dividend
    PyObject * field = PyObject_GetAttrString(_pymsg, "dividend");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dividend = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // divisor
    PyObject * field = PyObject_GetAttrString(_pymsg, "divisor");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->divisor = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_interfaces__srv__modulus_division__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ModulusDivision_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_interfaces.srv._modulus_division");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ModulusDivision_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_interfaces__srv__ModulusDivision_Request * ros_message = (custom_interfaces__srv__ModulusDivision_Request *)raw_ros_message;
  {  // dividend
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->dividend);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dividend", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // divisor
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->divisor);
    {
      int rc = PyObject_SetAttrString(_pymessage, "divisor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "custom_interfaces/srv/detail/modulus_division__struct.h"
// already included above
// #include "custom_interfaces/srv/detail/modulus_division__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_interfaces__srv__modulus_division__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_interfaces.srv._modulus_division.ModulusDivision_Response", full_classname_dest, 64) == 0);
  }
  custom_interfaces__srv__ModulusDivision_Response * ros_message = _ros_message;
  {  // quotient
    PyObject * field = PyObject_GetAttrString(_pymsg, "quotient");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->quotient = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // remainder
    PyObject * field = PyObject_GetAttrString(_pymsg, "remainder");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->remainder = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_interfaces__srv__modulus_division__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ModulusDivision_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_interfaces.srv._modulus_division");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ModulusDivision_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_interfaces__srv__ModulusDivision_Response * ros_message = (custom_interfaces__srv__ModulusDivision_Response *)raw_ros_message;
  {  // quotient
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->quotient);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quotient", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remainder
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->remainder);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remainder", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
