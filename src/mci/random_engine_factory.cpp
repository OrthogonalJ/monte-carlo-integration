#include "mci/random_engine_factory.h"

namespace mci {

RandomEngineFactory::RandomEngineFactory(bool use_global_random_engine) {
    if (use_global_random_engine) {
        this->random_engine = &(mci::get_global_random_engine());
    } else {
        unsigned seed = mci::time_based_seed();
        this->random_engine = new std::default_random_engine(seed);
    }
}

RandomEngineFactory::~RandomEngineFactory() {
    delete this->random_engine;
}

std::default_random_engine& RandomEngineFactory::operator()() {
    return *(this->random_engine);
}

};