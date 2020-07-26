#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include "mci/monte_carlo_integration.h"
#include "mci/numeric_types.h"
#include "mci/random_utils.h"

namespace py = pybind11;

PYBIND11_MODULE(mci_cpp_module, m) {
    m.doc() = "MCI CPP API";
    m.attr("REAL_INFINITY") = mci::REAL_INFINITY;
    m.attr("REAL_NEGATIVE_INFINITY") = mci::REAL_NEGATIVE_INFINITY;
    m.def("monte_carlo_integral", &mci::monte_carlo_integral);
    m.def("set_global_seed", &mci::set_global_seed);
}
