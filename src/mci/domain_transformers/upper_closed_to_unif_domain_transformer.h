#ifndef DOMAIN_TRANSFORMERS__UPPER_CLOSED_TO_UNIF_DOMAIN_TRANSFORMER_H_
#define DOMAIN_TRANSFORMERS__UPPER_CLOSED_TO_UNIF_DOMAIN_TRANSFORMER_H_

#include <cmath>
#include "mci/numeric_types.h"
#include "mci/domain_transformers/domain_transformer.h"

namespace mci {

class UpperClosedToUnifDomainTransformer : public mci::DomainTransformer {
private:
	mci::RealType upper_bound;
public:
	UpperClosedToUnifDomainTransformer(mci::RealType upper_bound);
	virtual ~UpperClosedToUnifDomainTransformer();
	virtual mci::RealType get_value(const mci::RealType& unif_val) const;
	virtual mci::RealType get_dx_dy(const mci::RealType& u) const;
};

}

#endif /* DOMAIN_TRANSFORMERS__UPPER_CLOSED_TO_UNIF_DOMAIN_TRANSFORMER_H_ */
