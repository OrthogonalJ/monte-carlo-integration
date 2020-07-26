# distutils: language = c++

#from mci.cpp_api_externals cimport BoostPythonObject

# NOTE: Headers below are located in <Project Root>/include

cdef extern from "numeric_types.h" namespace "mci":
    ctypedef long double RealType
    RealType REAL_INFINITY
    RealType REAL_NEGATIVE_INFINITY

#cdef extern from "monte_carlo_integration.h" namespace "mci":
#    RealType monte_carlo_integral(, size_t, RealType, RealType) except +