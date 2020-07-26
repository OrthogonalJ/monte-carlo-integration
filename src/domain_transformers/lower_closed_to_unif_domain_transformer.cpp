#include "lower_closed_to_unif_domain_transformer.h"

namespace mci {


LowerClosedToUnifDomainTransformer::LowerClosedToUnifDomainTransformer(mci::RealType lower_bound)
		: lower_bound(lower_bound) {};
	
LowerClosedToUnifDomainTransformer::~LowerClosedToUnifDomainTransformer() {};
	
mci::RealType LowerClosedToUnifDomainTransformer::get_value(const mci::RealType& u) const {
	return this->lower_bound - std::log(1.0 - u);
}

mci::RealType LowerClosedToUnifDomainTransformer::get_dx_dy(const mci::RealType& u) const {
	return 1.0 / (1.0 - u);
}

}
