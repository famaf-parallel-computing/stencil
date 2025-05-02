add_library(stencil_util INTERFACE)

target_sources(stencil_util
  INTERFACE
  FILE_SET HEADERS
  FILES util.hpp
)
