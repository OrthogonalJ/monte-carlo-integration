import timeit
import scipy.stats as spstats
import numpy as np
import mci

normal_rv = spstats.norm()

def square(x):
    return x **2

def normal_pdf(x):
    return normal_rv.pdf(x)

if __name__ == '__main__':
    repeats = 3
    print("mci.multi_threaded_monte_carlo_integral(square, 1e8, 0, 1)")
    times = timeit.repeat(
            "mci.multi_threaded_monte_carlo_integral(square, 1e8, 0, 1)",
            setup='from __main__ import square, mci', 
            number=1,
            repeat=repeats)
    print(f'time taken: best: {np.min(times) * 1000} ms, worst: {np.max(times) * 1000} ms of {repeats} trials')

    print("mci.monte_carlo_integral(square, 1e8, 0, 1)")
    times = timeit.repeat(
            "mci.monte_carlo_integral(square, 1e8, 0, 1)",
            setup='from __main__ import square, mci', 
            number=1,
            repeat=repeats)
    print(f'time taken: best: {np.min(times) * 1000} ms, worst: {np.max(times) * 1000} ms of {repeats} trials')