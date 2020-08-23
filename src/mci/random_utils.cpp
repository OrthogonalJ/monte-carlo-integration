#include "mci/random_utils.h"

namespace mci {

long long current_milliseconds_since_epoch() {
    const auto current_time = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(current_time).count();
}

unsigned time_based_seed() {
    long long current_milliseconds = current_milliseconds_since_epoch();
    constexpr long long max_seed = (long long) std::numeric_limits<unsigned>::max();
    return current_milliseconds % max_seed;
}

std::default_random_engine& get_global_random_engine() {
    static bool is_initialized(false);
    static std::default_random_engine instance;
    if (!is_initialized) {
        unsigned seed = time_based_seed();
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