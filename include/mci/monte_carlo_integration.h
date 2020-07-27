#ifndef MCI_MONTE_CARLO_INTEGRATOR_H_
#define MCI_MONTE_CARLO_INTEGRATOR_H_

#include <cstddef>
#include <functional>
#include <memory>
#include <random>
#include "mci/numeric_types.h"

namespace mci {

mci::RealType monte_carlo_integral(
	const std::function<RealType(RealType)>& base_function,
	long long num_samples, 
	mci::RealType lower_bound, 
	mci::RealType upper_bound
);

}

#endif /* MCI_MONTE_CARLO_INTEGRATOR_H_ */
