#ifndef MCI_NUMERIC_TYPES_H_
#define MCI_NUMERIC_TYPES_H_

#include <limits>

namespace mci {

typedef long double RealType;
static RealType REAL_INFINITY = std::numeric_limits<RealType>::infinity();
static RealType REAL_NEGATIVE_INFINITY = -REAL_INFINITY;

}

#endif /* MCI_NUMERIC_TYPES_H_ */
