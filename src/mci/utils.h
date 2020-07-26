#ifndef UTILS_H_
#define UTILS_H_

#include <limits>
#include "mci/numeric_types.h"

namespace mci {

bool is_infinity(const mci::RealType& value);

bool is_negative_infinity(const mci::RealType& value);

bool is_finite(const mci::RealType& value);

}

#endif /* UTILS_H_ */
