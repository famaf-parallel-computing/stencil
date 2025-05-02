#ifndef STENCIL_2D9_GENERIC_V512_HPP
#define STENCIL_2D9_GENERIC_V512_HPP

#include <cstdint>

void stencil_2D_9P_generic_v512_inner_ld(uint32_t n, float *__restrict in,
                                         float *__restrict out);

void stencil_2D_9P_generic_v512_inner_bperm(uint32_t n, float *__restrict in,
                                            float *__restrict out);

void stencil_2D_9P_generic_v512_outer_bperm(uint32_t n, float *__restrict in,
                                           float *__restrict out);

#endif