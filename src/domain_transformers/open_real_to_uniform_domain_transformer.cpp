#include "open_real_to_uniform_domain_transformer.h"

namespace mci {

OpenRealToUniformDomainTransformer::OpenRealToUniformDomainTransformer() {}

OpenRealToUniformDomainTransformer::~OpenRealToUniformDomainTransformer() {}
	
RealType OpenRealToUniformDomainTransformer::get_value(const mci::RealType& unif_value) const {
	return std::log(unif_value / (1.0 - unif_value));
}
	
RealType OpenRealToUniformDomainTransformer::get_dx_dy(const mci::RealType& unif_value) const {
	return 1.0 / (unif_value * (1.0 - unif_value));
}

}
