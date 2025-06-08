#ifndef STENCIL_OMP_HPP
#define STENCIL_OMP_HPP

#include <cstdint>

void stencil_omp_simd_2D_5P(uint32_t n, float *__restrict in, float *__restrict out);

void stencil_omp_simd_2D_9P(uint32_t n, float *__restrict in, float *__restrict out);

#endif