#include <memory>

#include <benchmark/benchmark.h>

#include <util.hpp>

#include <2D9P_generic_v512.hpp>

using namespace std;

static void BM_2D9P_generic_v512_inner_ld(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_2D_9P_generic_v512_inner_ld(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_2D9P_generic_v512_inner_ld)->RangeMultiplier(2)->Range(32, 32768);

static void BM_2D9P_generic_v512_inner_bperm(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_2D_9P_generic_v512_inner_bperm(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_2D9P_generic_v512_inner_bperm)
    ->RangeMultiplier(2)
    ->Range(32, 32768);

static void BM_2D9P_generic_v512_outer_bperm(benchmark::State &state) {
  const int n = state.range(0) + 4; // nxn + 4

  auto in = generateMatrix(n);
  unique_ptr<float[]> out{new float[n * n]{}};

  for (auto _ : state) {
    stencil_2D_9P_generic_v512_outer_bperm(n, in.get(), out.get());
  }

  const double operations = 10 * state.range(0) * state.range(0);
  state.counters["FLOPS"] = benchmark::Counter(
      operations, benchmark::Counter::kIsIterationInvariantRate);
}
BENCHMARK(BM_2D9P_generic_v512_outer_bperm)
    ->RangeMultiplier(2)
    ->Range(32, 32768);

BENCHMARK_MAIN();