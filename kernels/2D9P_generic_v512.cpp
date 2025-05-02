#include "2D9P_generic_v512.hpp"

// aligned is necessary by default it produces aligned mem ops
// but we want to use unaligned loads and stores
typedef float f32x8
    __attribute__((vector_size(8 * sizeof(float)), aligned(sizeof(float))));
typedef float f32x16
    __attribute__((vector_size(16 * sizeof(float)), aligned(sizeof(float))));

// just load data even if may be redundant
void stencil_2D_9P_generic_v512_inner_ld(uint32_t n, float *__restrict in,
                                         float *__restrict out) {
  for (uint32_t i = 2; i < n - 2; ++i) {
    for (uint32_t j = 2; j <= n - 18; j += 16) {
      auto u1 = *(f32x16 *)(&in[(i - 2) * n + j]);
      auto u2 = *(f32x16 *)(&in[(i - 1) * n + j]);
      auto d1 = *(f32x16 *)(&in[(i + 1) * n + j]);
      auto d2 = *(f32x16 *)(&in[(i + 2) * n + j]);

      auto ml1 = *(f32x16 *)(&in[i * n + j - 2]);
      auto ml2 = *(f32x16 *)(&in[i * n + j - 1]);

      auto mr1 = *(f32x16 *)(&in[i * n + j + 1]);
      auto mr2 = *(f32x16 *)(&in[i * n + j + 2]);

      auto c = *(f32x16 *)(&in[i * n + j]);

      auto r = .2f * (c + ml1 + ml2 + mr1 + mr2 + u1 + u2 + d1 + d2);
      *(f32x16 *)(&out[i * n + j]) = r;
    }
  }
}

// build unaligned with permutes
void stencil_2D_9P_generic_v512_inner_bperm(uint32_t n, float *__restrict in,
                                            float *__restrict out) {
  for (uint32_t i = 2; i < n - 2; ++i) {
    for (uint32_t j = 2; j <= n - 18; j += 16) {
      auto u1 = *(f32x16 *)(&in[(i - 2) * n + j]);
      auto u2 = *(f32x16 *)(&in[(i - 1) * n + j]);
      auto d1 = *(f32x16 *)(&in[(i + 1) * n + j]);
      auto d2 = *(f32x16 *)(&in[(i + 2) * n + j]);

      auto ml1 = *(f32x16 *)(&in[i * n + j - 2]);
      auto mr2 = *(f32x16 *)(&in[i * n + j + 2]);

      auto c = __builtin_shufflevector(ml1, mr2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                                       12, 13, 14, 15, 28, 29);
      auto ml2 = __builtin_shufflevector(ml1, mr2, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                                         10, 11, 12, 13, 14, 15, 28);
      auto mr1 = __builtin_shufflevector(ml1, mr2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                                         12, 13, 14, 15, 28, 29, 30);

      auto r = .2f * (c + ml1 + ml2 + mr1 + mr2 + u1 + u2 + d1 + d2);
      *(f32x16 *)(&out[i * n + j]) = r;
    }
  }
}

// build unaligned with permutes
void tencil_2D_9P_generic_v512_outer_bperm(uint32_t n, float *__restrict in,
                                           float *__restrict out) {
  for (uint32_t i = 2; i < n - 4; i += 2) {
    for (uint32_t j = 2; j < n - 10; j += 8) {
      auto uh = *(f32x16 *)(&in[(i - 2) * n + j]);
      auto ul = *(f32x16 *)(&in[(i - 1) * n + j]);
      auto dh = *(f32x16 *)(&in[(i + 2) * n + j]);
      auto dl = *(f32x16 *)(&in[(i + 3) * n + j]);

      auto mlh = *(f32x16 *)(&in[i * n + j - 2]);
      auto mll = *(f32x16 *)(&in[(i + 1) * n + j - 2]);

      auto u2 = __builtin_shufflevector(uh, ul, 0, 1, 2, 3, 4, 5, 6, 7, 16, 17,
                                        18, 19, 20, 21, 22, 23);
      auto u1 = __builtin_shufflevector(ul, mlh, 0, 1, 2, 3, 4, 5, 6, 7, 18, 19,
                                        20, 21, 22, 23, 24, 25);
      auto c = __builtin_shufflevector(mlh, mll, 2, 3, 4, 5, 6, 7, 8, 9, 18, 19,
                                       20, 21, 22, 23, 24, 25);
      auto d2 = __builtin_shufflevector(dh, dl, 0, 1, 2, 3, 4, 5, 6, 7, 16, 17,
                                        18, 19, 20, 21, 22, 23);
      auto d1 = __builtin_shufflevector(mll, dh, 2, 3, 4, 5, 6, 7, 8, 9, 16, 17,
                                        18, 19, 20, 21, 22, 23);
      auto l1 = __builtin_shufflevector(mlh, mll, 1, 2, 3, 4, 5, 6, 7, 8, 17,
                                        18, 19, 20, 21, 22, 23, 24);
      auto l2 = __builtin_shufflevector(mlh, mll, 0, 1, 2, 3, 4, 5, 6, 7, 16,
                                        17, 18, 19, 20, 21, 22, 23);
      auto r1 = __builtin_shufflevector(mlh, mll, 3, 4, 5, 6, 7, 8, 9, 10, 19,
                                        20, 21, 22, 23, 24, 25, 26);
      auto r2 = __builtin_shufflevector(mlh, mll, 4, 5, 6, 7, 8, 9, 10, 11, 20,
                                        21, 22, 23, 24, 25, 26, 27);

      auto r = .2f * (u1 + u2 + d1 + d2 + l2 + l1 + c + r1 + r2);
      *(f32x8 *)(&out[i * n + j]) = *(f32x8 *)(&r);
      *(f32x8 *)(&out[(i + 1) * n + j]) = *((f32x8 *)(&r) + 1);
    }
  }
}