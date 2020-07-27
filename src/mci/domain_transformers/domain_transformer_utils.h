#ifndef DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_UTILS_H_
#define DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_UTILS_H_

#include <iostream>
#include <cassert>
#include <limits>
#include <memory>
#include "mci/domain_transformers/finite_interval_to_unif_domain_transformer.h"
#include "mci/domain_transformers/lower_closed_to_unif_domain_transformer.h"
#include "mci/domain_transformers/open_real_to_uniform_domain_transformer.h"
#include "mci/domain_transformers/upper_closed_to_unif_domain_transformer.h"
#include "mci/numeric_types.h"
#include "mci/utils.h"
#include "mci/domain_transformers/domain_transformer.h"

namespace mci {

std::unique_ptr<mci::DomainTransformer> 
choose_domain_transformer(mci::RealType lower_bound, mci::RealType upper_bound);

}

#endif /* DOMAIN_TRANSFORMERS__DOMAIN_TRANSFORMER_UTILS_H_ */
