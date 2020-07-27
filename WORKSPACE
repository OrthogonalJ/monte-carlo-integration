load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

#### PYTHON ####

http_archive(
    name = "rules_python",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.0.2/rules_python-0.0.2.tar.gz",
    strip_prefix = "rules_python-0.0.2",
    sha256 = "b5668cde8bb6e3515057ef465a35ad712214962f0b3a314e551204266c7be90c",
)


#### PYBIND11 ####

http_archive(
  name = "pybind11_bazel",
  strip_prefix = "pybind11_bazel-203508e14aab7309892a1c5f7dd05debda22d9a5",
  urls = ["https://github.com/pybind/pybind11_bazel/archive/203508e14aab7309892a1c5f7dd05debda22d9a5.zip"],
)
# We still require the pybind library.
http_archive(
  name = "pybind11",
  build_file = "@pybind11_bazel//:pybind11.BUILD",
  strip_prefix = "pybind11-2.5.0",
  urls = ["https://github.com/pybind/pybind11/archive/v2.5.0.tar.gz"],
)
load("@pybind11_bazel//:python_configure.bzl", "python_configure")
python_configure(name = "local_config_python")
