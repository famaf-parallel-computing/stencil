cmake_minimum_required(VERSION 3.31)
project(stencil CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

find_package(OpenMP REQUIRED)

add_subdirectory(util)

add_subdirectory(kernels)

find_package(benchmark REQUIRED CONFIG)
add_subdirectory(benchmarks)

enable_testing()
include(GoogleTest)
find_package(GTest REQUIRED CONFIG)
add_subdirectory(tests)