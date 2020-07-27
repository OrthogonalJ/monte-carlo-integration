#include "mci/utils.h"

namespace mci {

bool is_infinity(mci::RealType value) {
	return value == mci::REAL_INFINITY;
}

bool is_negative_infinity(mci::RealType value) {
	return value == mci::REAL_NEGATIVE_INFINITY;
}

bool is_finite(mci::RealType value) {
	return !(is_infinity(value) || is_negative_infinity(value));
}

}
