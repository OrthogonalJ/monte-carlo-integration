#ifndef RANDOM_ENGINE_FACTORY_H_
#define RANDOM_ENGINE_FACTORY_H_

#include <random>
#include "mci/random_utils.h"

namespace mci {

class RandomEngineFactory {
private:
    std::default_random_engine* random_engine;
public:
    RandomEngineFactory(bool use_global_random_engine);
    ~RandomEngineFactory();
    std::default_random_engine& operator()();
};

}

#endif /* RANDOM_ENGINE_FACTORY_H_ */