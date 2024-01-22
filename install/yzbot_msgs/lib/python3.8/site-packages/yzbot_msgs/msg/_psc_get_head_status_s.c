// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from yzbot_msgs:msg/PscGetHeadStatus.idl
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
#include "yzbot_msgs/msg/detail/psc_get_head_status__struct.h"
#include "yzbot_msgs/msg/detail/psc_get_head_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool yzbot_msgs__msg__psc_get_head_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
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
    assert(strncmp("yzbot_msgs.msg._psc_get_head_status.PscGetHeadStatus", full_classname_dest, 52) == 0);
  }
  yzbot_msgs__msg__PscGetHeadStatus * ros_message = _ros_message;
  {  // get_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "get_level");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->get_level = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // get_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "get_pitch");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->get_pitch = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * yzbot_msgs__msg__psc_get_head_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PscGetHeadStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("yzbot_msgs.msg._psc_get_head_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PscGetHeadStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  yzbot_msgs__msg__PscGetHeadStatus * ros_message = (yzbot_msgs__msg__PscGetHeadStatus *)raw_ros_message;
  {  // get_level
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->get_level);
    {
      int rc = PyObject_SetAttrString(_pymessage, "get_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // get_pitch
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->get_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "get_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
