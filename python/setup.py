import glob
import os
import re
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import setuptools
import sys


#### CONSTANTS ####
__version__ = '0.0.1'
MCI_INCLUDE_DIR = '../include'
MCI_SRC_DIR = '../src'


#### HELPERS ####

def standardize_src_file_paths(paths, relative_to_dir):
    paths = relativize_paths(paths, relative_to_dir)
    paths = ensure_unix_style_paths(paths)
    # Sort input source files to ensure bit-for-bit reproducible builds
    # (https://github.com/pybind/python_example/pull/53)
    paths = sorted(paths)
    return paths


def ensure_unix_style_paths(paths):
    pattern = re.compile(r'\\')
    if isinstance(paths, list):
        return [pattern.sub('/', p) for p in paths]
    return pattern.sub('/', paths)


def relativize_paths(paths, base_dir):
    return [os.path.relpath(p, base_dir) for p in paths]


class get_pybind_include(object):
    """Helper class to determine the pybind11 include path
    The purpose of this class is to postpone importing pybind11
    until it is actually installed, so that the ``get_include()``
    method can be invoked. """

    def __str__(self):
        import pybind11
        return pybind11.get_include()


# cf http://bugs.python.org/issue26689
def has_flag(compiler, flagname):
    """Return a boolean indicating whether a flag name is supported on
    the specified compiler.
    """
    import tempfile
    import os
    with tempfile.NamedTemporaryFile('w', suffix='.cpp', delete=False) as f:
        f.write('int main (int argc, char **argv) { return 0; }')
        fname = f.name
    try:
        compiler.compile([fname], extra_postargs=[flagname])
    except setuptools.distutils.errors.CompileError:
        return False
    finally:
        try:
            os.remove(fname)
        except OSError:
            pass
    return True


def cpp_flag(compiler):
    """Return the -std=c++[11/14/17] compiler flag.
    The newer version is prefered over c++11 (when it is available).
    """
    flags = ['-std=c++17', '-std=c++14', '-std=c++11']

    for flag in flags:
        if has_flag(compiler, flag):
            return flag

    raise RuntimeError('Unsupported compiler -- at least C++11 support '
                       'is needed!')


class BuildExt(build_ext):
    """A custom build extension for adding compiler-specific options."""
    c_opts = {
        'msvc': ['/EHsc'],
        'unix': [],
    }
    l_opts = {
        'msvc': [],
        'unix': [],
    }

    if sys.platform == 'darwin':
        darwin_opts = ['-stdlib=libc++', '-mmacosx-version-min=10.7']
        c_opts['unix'] += darwin_opts
        l_opts['unix'] += darwin_opts

    def build_extensions(self):
        ct = self.compiler.compiler_type
        opts = self.c_opts.get(ct, [])
        link_opts = self.l_opts.get(ct, [])
        if ct == 'unix':
            opts.append(cpp_flag(self.compiler))
            if has_flag(self.compiler, '-fvisibility=hidden'):
                opts.append('-fvisibility=hidden')

        for ext in self.extensions:
            ext.define_macros = [('VERSION_INFO', '"{}"'.format(self.distribution.get_version()))]
            ext.extra_compile_args = opts
            ext.extra_link_args = link_opts
        build_ext.build_extensions(self)


#### SETUP CONFIG ####

core_src_files = glob.glob(MCI_SRC_DIR + '/**/*.cpp', recursive=True)

ext_modules = [
    Extension(
        'mci_cpp_module',
        standardize_src_file_paths(
            [
                'cpp_api/mci_cpp_module.cpp', 
                *core_src_files
            ], 
            relative_to_dir='.'
        ),
        include_dirs=[
            MCI_INCLUDE_DIR,
            MCI_SRC_DIR,
            # Path to pybind11 headers
            get_pybind_include()
        ],
        language='c++'
    ),
]

setup(
    name='monte_carlo_integration',
    version=__version__,
    description='Monte Carlo Integration',
    ext_modules=ext_modules,
    setup_requires=['pybind11>=2.5.0'],
    cmdclass={'build_ext': BuildExt},
    zip_safe=False,
    packages=[''],
    package_dir={'': 'mci'}
)
