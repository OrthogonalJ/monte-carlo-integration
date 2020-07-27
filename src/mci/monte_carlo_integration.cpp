#include "mci/monte_carlo_integration.h"
#include "mci/domain_transformers/domain_transformer_utils.h"
#include "mci/random_utils.h"

namespace mci {

mci::RealType monte_carlo_integral(
		const std::function<mci::RealType(mci::RealType)>& base_function, 
		long long num_samples,
		const std::unique_ptr<mci::DomainTransformer>& domain_transformer) {
	std::default_random_engine& rng = mci::get_global_random_engine();
	std::uniform_real_distribution<mci::RealType> unif_dist(0.0, 1.0);

	mci::RealType running_mean = 0;
	for (long long i = 0; i < num_samples; ++i) {
		mci::RealType unif_val = unif_dist(rng);
		mci::RealType integrand = domain_transformer->get_value(unif_val);
		mci::RealType dx_dy = domain_transformer->get_dx_dy(unif_val);
		running_mean += base_function(integrand) * dx_dy / num_samples;
	}

    return running_mean;
}

mci::RealType monte_carlo_integral(
		const std::function<RealType(RealType)>& base_function,
		long long num_samples, 
		mci::RealType lower_bound, 
		mci::RealType upper_bound) {
	std::unique_ptr<mci::DomainTransformer> domain_transformer = mci::choose_domain_transformer(lower_bound, upper_bound);
	return mci::monte_carlo_integral(base_function, num_samples, domain_transformer);
}

}
