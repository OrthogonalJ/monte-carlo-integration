#include "mci/domain_transformers/open_real_to_uniform_domain_transformer.h"

namespace mci {

OpenRealToUniformDomainTransformer::OpenRealToUniformDomainTransformer() {}

OpenRealToUniformDomainTransformer::~OpenRealToUniformDomainTransformer() {}
	
mci::RealType
OpenRealToUniformDomainTransformer::get_value(mci::RealType unif_value) const {
	return std::log(unif_value / (1.0 - unif_value));
}
	
mci::RealType 
OpenRealToUniformDomainTransformer::get_dx_dy(mci::RealType unif_value) const {
	return 1.0 / (unif_value * (1.0 - unif_value));
}

}
