#include "domain_transformer.h"

namespace mci {

RealType DomainTransformer::get_value(const RealType&) const {
	std::cout << "DomainTransformer::get_value called" << std::endl;
	throw "NOT_IMPLEMENTED_ERROR";
}

RealType DomainTransformer::get_dx_dy(const RealType&) const {
	std::cout << "DomainTransformer::get_dx_dy called" << std::endl;
	throw "NOT_IMPLEMENTED_ERROR";
};

}
