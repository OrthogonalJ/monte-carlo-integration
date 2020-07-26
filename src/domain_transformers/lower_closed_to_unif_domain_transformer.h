#ifndef DOMAIN_TRANSFORMERS__LOWER_CLOSED_TO_UNIF_DOMAIN_TRANSFORMER_H_
#define DOMAIN_TRANSFORMERS__LOWER_CLOSED_TO_UNIF_DOMAIN_TRANSFORMER_H_

#include <cmath>
#include "numeric_types.h"
#include "domain_transformer.h"

namespace mci {

class LowerClosedToUnifDomainTransformer : public mci::DomainTransformer {
private:
	mci::RealType lower_bound;
public:
	LowerClosedToUnifDomainTransformer(mci::RealType lower_bound);
	virtual ~LowerClosedToUnifDomainTransformer();
	virtual mci::RealType get_value(const mci::RealType& u) const;
	virtual mci::RealType get_dx_dy(const mci::RealType& u) const;
};

}

#endif /* DOMAIN_TRANSFORMERS__LOWER_CLOSED_TO_UNIF_DOMAIN_TRANSFORMER_H_ */
