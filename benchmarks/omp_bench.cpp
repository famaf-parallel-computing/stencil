#include <memory>

#include <benchmark/benchmark.h>

#include <util.hpp>

#include <omp_kernels.hpp>

using namespace std;

static void BM_omp_simd_2D5P(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_omp_simd_2D_5P(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_omp_simd_2D5P)->RangeMultiplier(2)->Range(32, 32768);

static void BM_omp_simd_2D9P(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_omp_simd_2D_9P(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_omp_simd_2D5P)->RangeMultiplier(2)->Range(32, 32768);

static void BM_omp_par_simd_2D5P(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_omp_par_simd_2D_5P(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_omp_par_simd_2D5P)->RangeMultiplier(2)->Range(32, 32768);

static void BM_omp_par_simd_2D9P(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_omp_par_simd_2D_9P(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_omp_par_simd_2D5P)->RangeMultiplier(2)->Range(32, 32768);

BENCHMARK_MAIN();