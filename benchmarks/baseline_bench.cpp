#include <cstdint>
#include <memory>

#include <benchmark/benchmark.h>

#include <util.hpp>

#include <baseline.hpp>

using namespace std;

static void BM_2D5P_baseline(benchmark::State &state) {
  const int n = state.range(0) + 2; // nxn + 2

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_2D_5P(n, in.get(), out.get());
  }

  const double operations = 6 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_2D5P_baseline)->RangeMultiplier(2)->Range(32, 4096);

static void BM_2D9P_baseline(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_2D_9P(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_2D9P_baseline)->RangeMultiplier(2)->Range(32, 4096);

BENCHMARK_MAIN();