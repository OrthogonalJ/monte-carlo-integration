from setuptools import setup, find_packages
from setuptools.extension import Extension
import os

# NOTE: All paths relative to <Project Root Dir>/python
SRC_DIR = '.'
MCI_INC_DIR = '../include'
# MCI_LIB_DIR = '../build'
# MCI_STATIC_LIB = 'mci'
MCI_STATIC_LIB_FILE = '../build/libmci.a'
# NOTE: Set this to False before release
USE_CYTHON = True

ext = '.pyx' if USE_CYTHON else '.cpp'
extensions = [
    Extension(
        name='*', 
        sources=[SRC_DIR + '/**/*' + ext],
        include_dirs=[
            MCI_INC_DIR,
            os.environ['BOOST_LIB_DIR']
        ],
        extra_objects=[MCI_STATIC_LIB_FILE]
        #library_dirs=[MCI_LIB_DIR],
        #libraries=[MCI_STATIC_LIB]
    )
]

if USE_CYTHON:
    from Cython.Build import cythonize
    extensions = cythonize(
        extensions, 
        compiler_directives={'language_level': '3'},
        annotate=True
    )

setup(
    name='monte_carlo_integration',
    package_dir={'': SRC_DIR},
    packages=find_packages(SRC_DIR),
    ext_modules=extensions,
    zip_safe=False
)
