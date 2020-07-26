#ifndef MIC__PYTHON__CPP_UTILS
#define MIC__PYTHON__CPP_UTILS

#include <boost/python/object.hpp>

namespace mci {
namespace python {

// Source: https://stackoverflow.com/a/39052204
inline boost::python::object get_as_bpo(PyObject* o) {
    return boost::python::object(boost::python::handle<>(boost::python::borrowed(o)));
}

}
}

#endif /* MIC__PYTHON__CPP_UTILS */