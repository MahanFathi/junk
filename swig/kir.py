# This file was automatically generated by SWIG (http://www.swig.org).
# Version 4.0.1
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
if _swig_python_version_info < (2, 7, 0):
    raise RuntimeError("Python 2.7 or later required")

# Import the low-level C/C++ module
if __package__ or "." in __name__:
    from . import _kir
else:
    import _kir

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "thisown":
            self.this.own(value)
        elif name == "this":
            set(self, name, value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


class SwigPyIterator(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _kir.delete_SwigPyIterator

    def value(self):
        return _kir.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _kir.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _kir.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _kir.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _kir.SwigPyIterator_equal(self, x)

    def copy(self):
        return _kir.SwigPyIterator_copy(self)

    def next(self):
        return _kir.SwigPyIterator_next(self)

    def __next__(self):
        return _kir.SwigPyIterator___next__(self)

    def previous(self):
        return _kir.SwigPyIterator_previous(self)

    def advance(self, n):
        return _kir.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _kir.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _kir.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _kir.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _kir.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _kir.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _kir.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self

# Register SwigPyIterator in _kir:
_kir.SwigPyIterator_swigregister(SwigPyIterator)

class FloatVector(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def iterator(self):
        return _kir.FloatVector_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _kir.FloatVector___nonzero__(self)

    def __bool__(self):
        return _kir.FloatVector___bool__(self)

    def __len__(self):
        return _kir.FloatVector___len__(self)

    def __getslice__(self, i, j):
        return _kir.FloatVector___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _kir.FloatVector___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _kir.FloatVector___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _kir.FloatVector___delitem__(self, *args)

    def __getitem__(self, *args):
        return _kir.FloatVector___getitem__(self, *args)

    def __setitem__(self, *args):
        return _kir.FloatVector___setitem__(self, *args)

    def pop(self):
        return _kir.FloatVector_pop(self)

    def append(self, x):
        return _kir.FloatVector_append(self, x)

    def empty(self):
        return _kir.FloatVector_empty(self)

    def size(self):
        return _kir.FloatVector_size(self)

    def swap(self, v):
        return _kir.FloatVector_swap(self, v)

    def begin(self):
        return _kir.FloatVector_begin(self)

    def end(self):
        return _kir.FloatVector_end(self)

    def rbegin(self):
        return _kir.FloatVector_rbegin(self)

    def rend(self):
        return _kir.FloatVector_rend(self)

    def clear(self):
        return _kir.FloatVector_clear(self)

    def get_allocator(self):
        return _kir.FloatVector_get_allocator(self)

    def pop_back(self):
        return _kir.FloatVector_pop_back(self)

    def erase(self, *args):
        return _kir.FloatVector_erase(self, *args)

    def __init__(self, *args):
        _kir.FloatVector_swiginit(self, _kir.new_FloatVector(*args))

    def push_back(self, x):
        return _kir.FloatVector_push_back(self, x)

    def front(self):
        return _kir.FloatVector_front(self)

    def back(self):
        return _kir.FloatVector_back(self)

    def assign(self, n, x):
        return _kir.FloatVector_assign(self, n, x)

    def resize(self, *args):
        return _kir.FloatVector_resize(self, *args)

    def insert(self, *args):
        return _kir.FloatVector_insert(self, *args)

    def reserve(self, n):
        return _kir.FloatVector_reserve(self, n)

    def capacity(self):
        return _kir.FloatVector_capacity(self)
    __swig_destroy__ = _kir.delete_FloatVector

# Register FloatVector in _kir:
_kir.FloatVector_swigregister(FloatVector)

class Kir(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def __init__(self, dickName, pG, pL):
        _kir.Kir_swiginit(self, _kir.new_Kir(dickName, pG, pL))
    __swig_destroy__ = _kir.delete_Kir

    def getVolume(self):
        return _kir.Kir_getVolume(self)

    def setPenises(self, ps):
        return _kir.Kir_setPenises(self, ps)

    def getPenises(self):
        return _kir.Kir_getPenises(self)

    def getName(self):
        return _kir.Kir_getName(self)

# Register Kir in _kir:
_kir.Kir_swigregister(Kir)



