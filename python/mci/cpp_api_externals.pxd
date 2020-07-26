# distutils: language = c++

from mci.cpp_core_externals cimport RealType

cdef extern from "../cpp_api/boost_wrapper.h":
    cdef cppclass BoostPythonObject "boost::python::object":
        BoostPythonObject()
    
    BoostPythonObject get_as_bpo "mci::python::get_as_bpo" (object)

cdef extern from "../cpp_api/monte_carlo_integration_py.h" namespace "mci::python":
    RealType monte_carlo_integral(BoostPythonObject, size_t, RealType, RealType) except +
