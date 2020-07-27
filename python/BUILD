load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:defs.bzl", "py_library")

pybind_extension(
    name = "mci_py",
    srcs = ["cpp_api/mci_cpp_module.cpp"],
    deps = ["//:mci_static"]
)

genrule(
    name = "mci_py_pyd",
    srcs = ["mci_py.so"],
    outs = ["mci_py.pyd"],
    visibility = ["//python:__pkg__"],
    cmd = "cp $< $@",
    output_to_bindir = 1
)

pybind_library(
    name = "mci_py_lib",
    srcs = ["cpp_api/mci_cpp_module.cpp"],
    deps = ["//:mci_static"]
)

filegroup(
    name = "mci_python_src",
    srcs = [
        "mci/__init__.py"
    ]
)

py_library(
    name = "mci",
    data = ["mci_py.pyd"],
    srcs = [":mci_python_src"]
)

genrule(
    name = "mci2",
    srcs = ["mci_python_src"],
    outs = [glob(["mci/**"])],
    cmd = "cp $< $@",
    output_to_bindir = 1
)
