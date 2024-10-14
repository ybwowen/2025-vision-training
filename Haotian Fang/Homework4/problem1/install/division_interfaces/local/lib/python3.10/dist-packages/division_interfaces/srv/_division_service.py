# generated from rosidl_generator_py/resource/_idl.py.em
# with input from division_interfaces:srv/DivisionService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DivisionService_Request(type):
    """Metaclass of message 'DivisionService_Request'."""

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
            module = import_type_support('division_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'division_interfaces.srv.DivisionService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__division_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__division_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__division_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__division_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__division_service__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DivisionService_Request(metaclass=Metaclass_DivisionService_Request):
    """Message class 'DivisionService_Request'."""

    __slots__ = [
        '_dividend',
        '_divisor',
    ]

    _fields_and_field_types = {
        'dividend': 'int64',
        'divisor': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.dividend = kwargs.get('dividend', int())
        self.divisor = kwargs.get('divisor', int())

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
        if self.dividend != other.dividend:
            return False
        if self.divisor != other.divisor:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def dividend(self):
        """Message field 'dividend'."""
        return self._dividend

    @dividend.setter
    def dividend(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dividend' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'dividend' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._dividend = value

    @builtins.property
    def divisor(self):
        """Message field 'divisor'."""
        return self._divisor

    @divisor.setter
    def divisor(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'divisor' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'divisor' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._divisor = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DivisionService_Response(type):
    """Metaclass of message 'DivisionService_Response'."""

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
            module = import_type_support('division_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'division_interfaces.srv.DivisionService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__division_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__division_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__division_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__division_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__division_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DivisionService_Response(metaclass=Metaclass_DivisionService_Response):
    """Message class 'DivisionService_Response'."""

    __slots__ = [
        '_quotient',
        '_remainder',
    ]

    _fields_and_field_types = {
        'quotient': 'int64',
        'remainder': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.quotient = kwargs.get('quotient', int())
        self.remainder = kwargs.get('remainder', int())

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
        if self.quotient != other.quotient:
            return False
        if self.remainder != other.remainder:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def quotient(self):
        """Message field 'quotient'."""
        return self._quotient

    @quotient.setter
    def quotient(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'quotient' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'quotient' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._quotient = value

    @builtins.property
    def remainder(self):
        """Message field 'remainder'."""
        return self._remainder

    @remainder.setter
    def remainder(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'remainder' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'remainder' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._remainder = value


class Metaclass_DivisionService(type):
    """Metaclass of service 'DivisionService'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('division_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'division_interfaces.srv.DivisionService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__division_service

            from division_interfaces.srv import _division_service
            if _division_service.Metaclass_DivisionService_Request._TYPE_SUPPORT is None:
                _division_service.Metaclass_DivisionService_Request.__import_type_support__()
            if _division_service.Metaclass_DivisionService_Response._TYPE_SUPPORT is None:
                _division_service.Metaclass_DivisionService_Response.__import_type_support__()


class DivisionService(metaclass=Metaclass_DivisionService):
    from division_interfaces.srv._division_service import DivisionService_Request as Request
    from division_interfaces.srv._division_service import DivisionService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
