#ifndef RANDOM_UTILS_H_
#define RANDOM_UTILS_H_

#include <chrono>
#include <random>
#include <iostream>

namespace mci {

std::default_random_engine& get_global_random_engine();
void set_global_seed(unsigned seed);

}

#endif /* RANDOM_UTILS_H_ */