#include "utils.h"

namespace mci {

bool is_infinity(const mci::RealType& value) {
	return value == mci::REAL_INFINITY;
}

bool is_negative_infinity(const mci::RealType& value) {
	return value == mci::REAL_NEGATIVE_INFINITY;
}

bool is_finite(const mci::RealType& value) {
	return !(is_infinity(value) || is_negative_infinity(value));
}

}
