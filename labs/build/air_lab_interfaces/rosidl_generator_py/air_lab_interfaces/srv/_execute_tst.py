# generated from rosidl_generator_py/resource/_idl.py.em
# with input from air_lab_interfaces:srv/ExecuteTst.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ExecuteTst_Request(type):
    """Metaclass of message 'ExecuteTst_Request'."""

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
            module = import_type_support('air_lab_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'air_lab_interfaces.srv.ExecuteTst_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__execute_tst__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__execute_tst__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__execute_tst__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__execute_tst__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__execute_tst__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteTst_Request(metaclass=Metaclass_ExecuteTst_Request):
    """Message class 'ExecuteTst_Request'."""

    __slots__ = [
        '_tst_file',
    ]

    _fields_and_field_types = {
        'tst_file': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.tst_file = kwargs.get('tst_file', str())

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
        if self.tst_file != other.tst_file:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def tst_file(self):
        """Message field 'tst_file'."""
        return self._tst_file

    @tst_file.setter
    def tst_file(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'tst_file' field must be of type 'str'"
        self._tst_file = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteTst_Response(type):
    """Metaclass of message 'ExecuteTst_Response'."""

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
            module = import_type_support('air_lab_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'air_lab_interfaces.srv.ExecuteTst_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__execute_tst__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__execute_tst__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__execute_tst__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__execute_tst__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__execute_tst__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteTst_Response(metaclass=Metaclass_ExecuteTst_Response):
    """Message class 'ExecuteTst_Response'."""

    __slots__ = [
        '_success',
        '_my_error',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'my_error': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.my_error = kwargs.get('my_error', str())

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
        if self.success != other.success:
            return False
        if self.my_error != other.my_error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @property
    def my_error(self):
        """Message field 'my_error'."""
        return self._my_error

    @my_error.setter
    def my_error(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'my_error' field must be of type 'str'"
        self._my_error = value


class Metaclass_ExecuteTst(type):
    """Metaclass of service 'ExecuteTst'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('air_lab_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'air_lab_interfaces.srv.ExecuteTst')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__execute_tst

            from air_lab_interfaces.srv import _execute_tst
            if _execute_tst.Metaclass_ExecuteTst_Request._TYPE_SUPPORT is None:
                _execute_tst.Metaclass_ExecuteTst_Request.__import_type_support__()
            if _execute_tst.Metaclass_ExecuteTst_Response._TYPE_SUPPORT is None:
                _execute_tst.Metaclass_ExecuteTst_Response.__import_type_support__()


class ExecuteTst(metaclass=Metaclass_ExecuteTst):
    from air_lab_interfaces.srv._execute_tst import ExecuteTst_Request as Request
    from air_lab_interfaces.srv._execute_tst import ExecuteTst_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
