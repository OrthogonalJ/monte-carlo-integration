#ifndef DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_UTILS_H_
#define DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_UTILS_H_

#include <iostream>
#include <cassert>
#include <limits>
#include <memory>
#include "finite_interval_to_unif_domain_transformer.h"
#include "lower_closed_to_unif_domain_transformer.h"
#include "open_real_to_uniform_domain_transformer.h"
#include "upper_closed_to_unif_domain_transformer.h"
#include "numeric_types.h"
#include "../utils.h"
#include "domain_transformer.h"

namespace mci {

std::unique_ptr<mci::DomainTransformer> choose_domain_transformer(
		const mci::RealType& lower_bound, const mci::RealType& upper_bound);

}

#endif /* DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_UTILS_H_ */
