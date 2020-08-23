#include "mci/monte_carlo_integration.h"
#include "mci/domain_transformers/domain_transformer_utils.h"
#include "mci/random_utils.h"
#include "mci/random_engine_factory.h"

namespace mci {

mci::RealType monte_carlo_integral(
		const std::function<mci::RealType(mci::RealType)>& base_function, 
		long long num_samples,
		const std::unique_ptr<mci::DomainTransformer>& domain_transformer,
        bool use_global_random_engine = false) {
    mci::RandomEngineFactory random_engine_factory(use_global_random_engine);
    std::default_random_engine& rng = random_engine_factory();

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

mci::RealType multi_threaded_monte_carlo_integral(
        const std::function<mci::RealType(mci::RealType)>& base_function,
        long long num_samples, 
        mci::RealType lower_bound, 
        mci::RealType upper_bound,
        int num_threads) {
    
    typedef std::function<void(
        const std::function<mci::RealType(mci::RealType)>&,
        long long,
        mci::RealType,
        mci::RealType,
        mci::RealType&
    )> IntegralFnType;

    const IntegralFnType integral_fn = [](
            const std::function<mci::RealType(mci::RealType)> base_function,
            long long num_samples, 
            mci::RealType lower_bound, 
            mci::RealType upper_bound,
            mci::RealType& output) {
        std::unique_ptr<mci::DomainTransformer> domain_transformer = mci::choose_domain_transformer(
                lower_bound, upper_bound);
        output = mci::monte_carlo_integral(base_function, num_samples, 
                domain_transformer, false);
    };

    std::vector<std::thread> threads;
    std::vector<mci::RealType> thread_means(num_threads, 0.0);
    const long long batch_size = num_samples / num_threads;
    for (int i = 0; i < num_threads; ++i) {
        mci::RealType& current_mean = thread_means[i];
        threads.push_back(std::thread(
            integral_fn, 
            std::ref(base_function),
            batch_size,
            lower_bound,
            upper_bound,
            std::ref(current_mean)
        ));
    }

    mci::RealType global_mean = 0.0;
    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
        global_mean += thread_means[i];
    }

    return global_mean;
}

}
