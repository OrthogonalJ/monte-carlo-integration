#include "mci/domain_transformers/upper_closed_to_unif_domain_transformer.h"

namespace mci {

UpperClosedToUnifDomainTransformer::UpperClosedToUnifDomainTransformer(mci::RealType upper_bound)
		: upper_bound(upper_bound) {}

UpperClosedToUnifDomainTransformer::~UpperClosedToUnifDomainTransformer() {}

mci::RealType 
UpperClosedToUnifDomainTransformer::get_value(mci::RealType unif_val) const {
	return this->upper_bound + std::log(unif_val);
}

mci::RealType 
UpperClosedToUnifDomainTransformer::get_dx_dy(mci::RealType unif_val) const {
	return 1.0 / unif_val;
}

}
