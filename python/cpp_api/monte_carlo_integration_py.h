#ifndef MCI__PYTHON__MONTE_CARLO_INTEGRATION
#define MCI__PYTHON__MONTE_CARLO_INTEGRATION

#include <functional>

#include <boost/python/object.hpp>
#include <boost/python/extract.hpp>
#include "monte_carlo_integration.h"
#include "numeric_types.h"

namespace mci {
namespace python {

typedef std::function<mci::RealType(const mci::RealType&)> _BaseFuncType;

mci::RealType monte_carlo_integral(
			const boost::python::object& base_function,
			const std::size_t& num_samples, const mci::RealType& lower_bound, 
			const mci::RealType& upper_bound) {
	_BaseFuncType _base_function = [&base_function](const mci::RealType& x) {
        boost::python::object result = base_function(boost::python::object(x));
        mci::RealType value = boost::python::extract<mci::RealType>(result);
        return value;
	};
    return mci::monte_carlo_integral(_base_function, num_samples, lower_bound, 
            upper_bound);
}

} // namespace python
} // namespace mci

#endif /* MCI__PYTHON__MONTE_CARLO_INTEGRATION */