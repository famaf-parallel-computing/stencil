#include <gtest/gtest.h>

#include <util.hpp>

#include <baseline.hpp>
#include <omp_kernels.hpp>

using namespace std;

TEST(stencil_omp_2D5PTest, correctness) {
  uint32_t n = 516; // nxn + 4
  auto in = generateMatrix(n);

  unique_ptr<float[]> outBaseline{new float[n * n]{}};
  unique_ptr<float[]> outKernel{new float[n * n]{}};

  stencil_2D_5P(n, in.get(), outBaseline.get());
  stencil_omp_simd_2D_5P(n, in.get(), outKernel.get());

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ASSERT_NEAR(outKernel[i * n + j], outBaseline[i * n + j], 1e-5)
          << "Mismatch at (" << i << ", " << j << "): "
          << "Kernel: " << outKernel[i * n + j] << ", "
          << "Baseline: " << outBaseline[i * n + j];
    }
  }
}

TEST(stencil_omp_2D9PTest, correctness) {
  uint32_t n = 516; // nxn + 4
  auto in = generateMatrix(n);

  unique_ptr<float[]> outBaseline{new float[n * n]{}};
  unique_ptr<float[]> outKernel{new float[n * n]{}};

  stencil_2D_9P(n, in.get(), outBaseline.get());
  stencil_omp_simd_2D_9P(n, in.get(), outKernel.get());

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ASSERT_NEAR(outKernel[i * n + j], outBaseline[i * n + j], 1e-5)
          << "Mismatch at (" << i << ", " << j << "): "
          << "Kernel: " << outKernel[i * n + j] << ", "
          << "Baseline: " << outBaseline[i * n + j];
    }
  }
}