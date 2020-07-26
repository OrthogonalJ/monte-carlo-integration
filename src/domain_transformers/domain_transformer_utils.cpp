#include "domain_transformer_utils.h"

namespace mci {

std::unique_ptr<mci::DomainTransformer> choose_domain_transformer(const mci::RealType& lower_bound, 
			const mci::RealType& upper_bound) {
	assert (lower_bound < upper_bound);
	std::unique_ptr<mci::DomainTransformer> domain_transformer;	
	if (mci::is_negative_infinity(lower_bound) && mci::is_infinity(upper_bound)) {
		std::cout << "Using OpenRealToUniformDomainTransformer" << std::endl;
		domain_transformer.reset(new OpenRealToUniformDomainTransformer());
	} else if (mci::is_negative_infinity(lower_bound) && mci::is_finite(upper_bound)) {
		std::cout << "Using UpperClosedToUnifDomainTransformer" << std::endl;
		domain_transformer.reset(new UpperClosedToUnifDomainTransformer(upper_bound));
	} else if (mci::is_finite(lower_bound) && mci::is_infinity(upper_bound)) {
		std::cout << "Using LowerClosedToUnifDomainTransformer" << std::endl;
		domain_transformer.reset(new LowerClosedToUnifDomainTransformer(lower_bound));
	} else if (mci::is_finite(lower_bound) && mci::is_finite(upper_bound)) {
		std::cout << "Using FiniteIntervalToUnifDomainTransformer" << std::endl;
		domain_transformer.reset(new FiniteIntervalToUnifDomainTransformer(lower_bound, upper_bound));
	} else {
		throw "NOT IMPLEMENTED ERROR";
	}
	return domain_transformer;
}

}
