#include "mci/domain_transformers/finite_interval_to_unif_domain_transformer.h"

namespace mci {

FiniteIntervalToUnifDomainTransformer::FiniteIntervalToUnifDomainTransformer(
		mci::RealType lower_bound, mci::RealType upper_bound) :
		lower_bound(lower_bound), upper_bound(upper_bound) {}

FiniteIntervalToUnifDomainTransformer::~FiniteIntervalToUnifDomainTransformer() {}

mci::RealType FiniteIntervalToUnifDomainTransformer::get_value(mci::RealType u) const {
	return this->lower_bound + (this->upper_bound - this->lower_bound) * u;
}

mci::RealType FiniteIntervalToUnifDomainTransformer::get_dx_dy(mci::RealType u) const {
	return this->upper_bound - this->lower_bound;
}

}
