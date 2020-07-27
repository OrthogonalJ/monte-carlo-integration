#ifndef DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_H_
#define DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_H_

#include <iostream>
#include "mci/numeric_types.h"

namespace mci {

class DomainTransformer {
public:
	DomainTransformer() {};
	virtual ~DomainTransformer() {};
	virtual RealType get_value(RealType) const;
	virtual RealType get_dx_dy(RealType) const;
};

}

#endif /* DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_H_ */
