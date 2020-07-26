#ifndef MCI_MONTE_CARLO_INTEGRATOR_H_
#define MCI_MONTE_CARLO_INTEGRATOR_H_

#include <cstddef>
#include <random>
#include <functional>
#include <memory>
#include "numeric_types.h"

namespace mci {

mci::RealType monte_carlo_integral(
	const std::function<RealType(const RealType&)>& base_function,
	const std::size_t& num_samples, const mci::RealType& lower_bound, 
	const mci::RealType& upper_bound
);

}

#endif /* MCI_MONTE_CARLO_INTEGRATOR_H_ */
