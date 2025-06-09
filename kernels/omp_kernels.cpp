#include "omp_kernels.hpp"

void stencil_omp_simd_2D_5P(uint32_t n, float *__restrict in,
                            float *__restrict out) {
  for (uint32_t i = 1; i < n - 1; ++i) {
#pragma omp simd
    for (uint32_t j = 1; j < n - 1; ++j) {
      out[i * n + j] = in[i * n + j] + in[i * n + j - 1] + in[i * n + j + 1] +
                       in[(i - 1) * n + j] + in[(i + 1) * n + j];
    }
  }
}

void stencil_omp_simd_2D_9P(uint32_t n, float *__restrict in,
                            float *__restrict out) {
  for (uint32_t i = 2; i < n - 2; ++i) {
#pragma omp simd
    for (uint32_t j = 2; j < n - 2; ++j) {
      out[i * n + j] =
          .2f *
          (in[i * n + j] + in[i * n + j - 2] + in[i * n + j - 1] +
           in[i * n + j + 1] + in[i * n + j + 2] + in[(i - 2) * n + j] +
           in[(i - 1) * n + j] + in[(i + 1) * n + j] + in[(i + 2) * n + j]);
    }
  }
}

void stencil_omp_par_simd_2D_5P(uint32_t n, float *__restrict in,
                                float *__restrict out) {
#pragma omp parallel for
  for (uint32_t i = 1; i < n - 1; ++i) {
#pragma omp simd
    for (uint32_t j = 1; j < n - 1; ++j) {
      out[i * n + j] = in[i * n + j] + in[i * n + j - 1] + in[i * n + j + 1] +
                       in[(i - 1) * n + j] + in[(i + 1) * n + j];
    }
  }
}

void stencil_omp_par_simd_2D_9P(uint32_t n, float *__restrict in,
                                float *__restrict out) {
#pragma omp parallel for
  for (uint32_t i = 2; i < n - 2; ++i) {
#pragma omp simd
    for (uint32_t j = 2; j < n - 2; ++j) {
      out[i * n + j] =
          .2f *
          (in[i * n + j] + in[i * n + j - 2] + in[i * n + j - 1] +
           in[i * n + j + 1] + in[i * n + j + 2] + in[(i - 2) * n + j] +
           in[(i - 1) * n + j] + in[(i + 1) * n + j] + in[(i + 2) * n + j]);
    }
  }
}