# distutils: language = c++
from mci.cpp_api_externals cimport BoostPythonObject, get_as_bpo
from mci.cpp_api_externals cimport monte_carlo_integral as c_monte_carlo_integral
from mci.cpp_core_externals cimport RealType, REAL_INFINITY, REAL_NEGATIVE_INFINITY

import numpy as np

def monte_carlo_integral(base_function, num_samples, lower_bound, upper_bound):
    cdef BoostPythonObject base_fn_obj = get_as_bpo(base_function)
    
    if np.isposinf(upper_bound):
        upper_bound = REAL_INFINITY
    
    if np.isneginf(lower_bound):
        lower_bound = REAL_NEGATIVE_INFINITY
    
    return c_monte_carlo_integral(base_fn_obj, num_samples, lower_bound, upper_bound)
