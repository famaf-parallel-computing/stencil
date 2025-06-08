add_executable(
  2D9P_generic_v512_test
)
target_sources(2D9P_generic_v512_test
  PRIVATE
  2D9P_generic_v512_test.cpp
)
target_link_libraries(2D9P_generic_v512_test
  PRIVATE
  stencil_util
  stencil_baseline stencil_2D9P_generic_v512
  GTest::gtest GTest::gtest_main
)

add_executable(
  omp_kernels_test
)
target_sources(omp_kernels_test
  PRIVATE
  omp_kernels_test.cpp
)
target_link_libraries(omp_kernels_test
  PRIVATE
  stencil_util
  stencil_baseline stencil_omp
  GTest::gtest GTest::gtest_main
)

gtest_discover_tests(2D9P_generic_v512_test)
