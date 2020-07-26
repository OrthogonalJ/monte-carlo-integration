# distutils: language = c++

#cdef extern from "<functional>" namespace "std":
#    cdef cppclass function[R, ArgType]
#        ctypedef result_type = R
#        function() except +
#        
#        R operator()(ArgType)