# generated from rosidl_generator_py/resource/_idl.py.em
# with input from yzbot_msgs:msg/RobotButton.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotButton(type):
    """Metaclass of message 'RobotButton'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('yzbot_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'yzbot_msgs.msg.RobotButton')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_button
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_button
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_button
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_button
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_button

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotButton(metaclass=Metaclass_RobotButton):
    """Message class 'RobotButton'."""

    __slots__ = [
        '_button_audio',
        '_button_power',
        '_zs',
    ]

    _fields_and_field_types = {
        'button_audio': 'int32',
        'button_power': 'int32',
        'zs': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.button_audio = kwargs.get('button_audio', int())
        self.button_power = kwargs.get('button_power', int())
        self.zs = kwargs.get('zs', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.button_audio != other.button_audio:
            return False
        if self.button_power != other.button_power:
            return False
        if self.zs != other.zs:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def button_audio(self):
        """Message field 'button_audio'."""
        return self._button_audio

    @button_audio.setter
    def button_audio(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'button_audio' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'button_audio' field must be an integer in [-2147483648, 2147483647]"
        self._button_audio = value

    @property
    def button_power(self):
        """Message field 'button_power'."""
        return self._button_power

    @button_power.setter
    def button_power(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'button_power' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'button_power' field must be an integer in [-2147483648, 2147483647]"
        self._button_power = value

    @property
    def zs(self):
        """Message field 'zs'."""
        return self._zs

    @zs.setter
    def zs(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'zs' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'zs' field must be an integer in [-2147483648, 2147483647]"
        self._zs = value
