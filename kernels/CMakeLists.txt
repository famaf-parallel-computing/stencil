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
