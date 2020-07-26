#include <Python.h>
#include "demolib.h"

static PyObject *
DemoLib_cFactorialSum(PyObject * self, PyObject * args)
{
    char * char_nums;
    if (!PyArg_ParseTuple(args, "s", &char_nums)) {
        return NULL;
    }
    unsigned long fact_sum;
    fact_sum = cfactorial(char_nums);
    return Py_BuildValue("i", fact_sum);
}

static PyObject *
DemoLib_iFactorialSum(PyObject * self, PyObject * args)
{
    PyObject * lst;
    if (!PyArg_ParseTuple(args, "O", &lst)) {
        return NULL;
    }
    int n = PyObject_Length(lst);
    if (n < 0) {
        return NULL;
    }
    long nums[n];
    for (int i = 0; i < n; i++) {
        PyLongObject * item = PyList_GetItem(lst, i);
        long num = PyLong_AsLong(item);
        nums[i] = num;
    }
    
}