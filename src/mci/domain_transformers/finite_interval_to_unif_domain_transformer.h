#ifndef DOMAIN_TRANSFORMERS__FINITE_INTERVAL_TO_UNIF_DOMAIN_TRANSFORMER_H_
#define DOMAIN_TRANSFORMERS__FINITE_INTERVAL_TO_UNIF_DOMAIN_TRANSFORMER_H_

#include "mci/numeric_types.h"
#include "mci/domain_transformers/domain_transformer.h"

namespace mci {

class FiniteIntervalToUnifDomainTransformer: public mci::DomainTransformer {
private:
	mci::RealType upper_bound;
	mci::RealType lower_bound;
public:
	FiniteIntervalToUnifDomainTransformer(mci::RealType lower_bound, mci::RealType upper_bound);
	virtual ~FiniteIntervalToUnifDomainTransformer();
	virtual mci::RealType get_value(mci::RealType u) const;
	virtual mci::RealType get_dx_dy(mci::RealType u) const;
};

}

#endif /* DOMAIN_TRANSFORMERS__FINITE_INTERVAL_TO_UNIF_DOMAIN_TRANSFORMER_H_ */
