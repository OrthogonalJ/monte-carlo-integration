from mci.mci_cpp_module import REAL_INFINITY, REAL_NEGATIVE_INFINITY, set_global_seed
from mci.mci_cpp_module import monte_carlo_integral as _monte_carlo_integral

def monte_carlo_integral(base_function, num_samples, lower_bound, upper_bound):
    return _monte_carlo_integral(base_function, int(num_samples), 
            float(lower_bound), float(upper_bound))
