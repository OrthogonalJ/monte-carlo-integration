#ifndef UTILS_H_
#define UTILS_H_

#include <limits>
#include "mci/numeric_types.h"

namespace mci {

bool is_infinity(mci::RealType value);

bool is_negative_infinity(mci::RealType value);

bool is_finite(mci::RealType value);

}

#endif /* UTILS_H_ */
