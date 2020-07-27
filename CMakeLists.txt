cmake_minimum_required(VERSION 3.12.0)
project(monte_carlo_integration)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY libs/shared/$<0:>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY libs/static/$<0:>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY libs/shared/$<0:>)

include_directories(include)
include_directories(src)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")

add_library(mci_static STATIC ${SOURCES})
set_target_properties(mci_static PROPERTIES LINK_FLAGS "/MACHINE:X64")

add_library(mci_shared SHARED ${SOURCES})
set_target_properties(mci_shared PROPERTIES LINK_FLAGS "/MACHINE:X64")