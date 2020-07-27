#include "mci/domain_transformers/domain_transformer.h"

namespace mci {

mci::RealType DomainTransformer::get_value(RealType) const {
	std::cout << "DomainTransformer::get_value called" << std::endl;
	throw "NOT_IMPLEMENTED_ERROR";
}

mci::RealType DomainTransformer::get_dx_dy(RealType) const {
	std::cout << "DomainTransformer::get_dx_dy called" << std::endl;
	throw "NOT_IMPLEMENTED_ERROR";
};

}
