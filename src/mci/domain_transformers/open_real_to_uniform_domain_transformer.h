#ifndef DOMAIN_TRANSFORMERS__OPEN_REAL_TO_UNIFORM_DOMAIN_TRANSFORMER_H_
#define DOMAIN_TRANSFORMERS__OPEN_REAL_TO_UNIFORM_DOMAIN_TRANSFORMER_H_

#include <cmath>
#include "mci/numeric_types.h"
#include "mci/domain_transformers/domain_transformer.h"

namespace mci {

class OpenRealToUniformDomainTransformer : public mci::DomainTransformer {
public:
	OpenRealToUniformDomainTransformer();
	virtual ~OpenRealToUniformDomainTransformer();
	virtual RealType get_value(mci::RealType unif_value) const;
	virtual RealType get_dx_dy(mci::RealType unif_value) const;
};

}

#endif /* DOMAIN_TRANSFORMERS__OPEN_REAL_TO_UNIFORM_DOMAIN_TRANSFORMER_H_ */
