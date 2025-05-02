#ifndef STENCIL_BASELINE_HPP
#define STENCIL_BASELINE_HPP

#include <cstdint>

void stencil_2D_5P(uint32_t n, float *__restrict in, float *__restrict out);

void stencil_2D_9P(uint32_t n, float *__restrict in, float *__restrict out);

#endif