#ifndef STENCIL_UTIL_HPP
#define STENCIL_UTIL_HPP

#include <cstdint>
#include <memory>
#include <print>
#include <random>

std::unique_ptr<float[]> generateMatrix(uint32_t n) {
  std::unique_ptr<float[]> matrix{new float[n * n]{}};

  std::random_device rd;
  std::minstd_rand gen(rd());
  std::uniform_real_distribution<float> dist(-10.f, 10.f);

  for (uint32_t i = 2; i < n - 2; ++i) {
    for (uint32_t j = 2; j < n - 2; ++j) {
      matrix[i * n + j] = dist(gen);
    }
  }

  return matrix;
}

void print_matrix(uint32_t n, float *matrix) {
  for (uint32_t i = 0; i < n; ++i) {
    for (uint32_t j = 0; j < n; ++j) {
      std::print("{:6.2f}", matrix[i * n + j]);
      if (j < n - 1) {
        std::print(", ");
      } else {
        std::println();
      }
    }
    std::println();
  }
}

#endif