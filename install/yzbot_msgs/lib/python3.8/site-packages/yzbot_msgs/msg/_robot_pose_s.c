// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from yzbot_msgs:msg/RobotPose.idl
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
#include "yzbot_msgs/msg/detail/robot_pose__struct.h"
#include "yzbot_msgs/msg/detail/robot_pose__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool yzbot_msgs__msg__robot_pose__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("yzbot_msgs.msg._robot_pose.RobotPose", full_classname_dest, 36) == 0);
  }
  yzbot_msgs__msg__RobotPose * ros_message = _ros_message;
  {  // robot_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->robot_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // robot_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->robot_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // robot_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->robot_yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // robot_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->robot_state = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * yzbot_msgs__msg__robot_pose__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RobotPose */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("yzbot_msgs.msg._robot_pose");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RobotPose");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  yzbot_msgs__msg__RobotPose * ros_message = (yzbot_msgs__msg__RobotPose *)raw_ros_message;
  {  // robot_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->robot_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->robot_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->robot_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_state
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->robot_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
