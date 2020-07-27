#include "mci/random_utils.h"

namespace mci {

std::default_random_engine& get_global_random_engine() {
    static bool is_initialized(false);
    static std::default_random_engine instance;
    if (!is_initialized) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        instance.seed(seed);
        is_initialized = true;
        std::cout << "Seeding global random engine" << std::endl;
    }
    return instance;
}

void set_global_seed(unsigned seed) {
    std::default_random_engine& engine = get_global_random_engine();
    engine.seed(seed);
}

}