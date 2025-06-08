add_library(stencil_baseline STATIC)
target_sources(stencil_baseline
  PRIVATE
  baseline.cpp
  PUBLIC
  FILE_SET HEADERS
  FILES baseline.hpp
)

add_library(stencil_2D9P_generic_v512 STATIC)
target_sources(stencil_2D9P_generic_v512
  PRIVATE
  2D9P_generic_v512.cpp
  PUBLIC
  FILE_SET HEADERS
  FILES 2D9P_generic_v512.hpp
)

add_library(stencil_omp STATIC)
target_sources(stencil_omp
  PRIVATE
  omp_kernels.cpp
  PUBLIC
  FILE_SET HEADERS
  FILES omp_kernels.hpp
)
target_link_libraries(stencil_omp
  PRIVATE
  OpenMP::OpenMP_CXX
)