import functools
import multiprocessing

from mci.mci_cpp_module import REAL_INFINITY, REAL_NEGATIVE_INFINITY, set_global_seed
from mci.mci_cpp_module import monte_carlo_integral as _monte_carlo_integral

def monte_carlo_integral(base_function, num_samples, lower_bound, upper_bound):
    return _monte_carlo_integral(base_function, int(num_samples), 
            float(lower_bound), float(upper_bound))


def multi_threaded_monte_carlo_integral(base_function, num_samples, lower_bound, 
        upper_bound, num_threads=None):
    num_threads = num_threads if num_threads is not None else multiprocessing.cpu_count()
    batch_size = num_samples // num_threads
    
    _integral_fn = functools.partial(monte_carlo_integral, base_function, 
            batch_size, lower_bound, upper_bound)
    
    with multiprocessing.Pool(num_threads) as pool:
        thread_results = [pool.apply_async(_integral_fn) for _ in range(num_threads)]
        thread_means = [result.get() for result in thread_results]
    
    global_mean = sum(thread_means) / num_threads
    return global_mean
