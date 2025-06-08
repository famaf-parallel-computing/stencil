add_executable(baseline_bench)
target_sources(baseline_bench
  PRIVATE
  baseline_bench.cpp
)
target_link_libraries(baseline_bench
  PRIVATE
  benchmark::benchmark benchmark::benchmark_main
  stencil_util
  stencil_baseline
)

add_executable(2D9P_generic_v512_bench)
target_sources(2D9P_generic_v512_bench
  PRIVATE
  2D9P_generic_v512_bench.cpp
)
target_link_libraries(2D9P_generic_v512_bench
  PRIVATE
  benchmark::benchmark benchmark::benchmark_main
  stencil_util
  stencil_2D9P_generic_v512
)

add_executable(omp_kernels_bench)
target_sources(omp_kernels_bench
  PRIVATE
  omp_bench.cpp
)
target_link_libraries(omp_kernels_bench
  PRIVATE
  benchmark::benchmark benchmark::benchmark_main
  stencil_util
  stencil_omp
)