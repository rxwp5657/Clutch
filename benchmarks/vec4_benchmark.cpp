#include <benchmark/benchmark.h>
#include "../include/vec4.hpp"

static void BM_Vec4SSEAddition(benchmark::State& state) {
  clutch::Vec4<float> vectors[100000]{};
  clutch::Vec4<float> res{1.0f, 1.0f, 1.0f, 1.0f};
  for (auto _ : state)
    for(auto& vector : vectors)
      res += vector;
}

BENCHMARK(BM_Vec4SSEAddition)->Unit(benchmark::kMicrosecond);

static void BM_Vec4SSESubstraction(benchmark::State& state) {
  clutch::Vec4<float> vectors[100000]{};
  clutch::Vec4<float> res{1.0f, 1.0f, 1.0f, 1.0f};
  for (auto _ : state)
    for(auto& vector : vectors)
      res -= vector;
}

BENCHMARK(BM_Vec4SSESubstraction)->Unit(benchmark::kMicrosecond);

static void BM_Vec4SSEMultiplication(benchmark::State& state) {
  clutch::Vec4<float> vectors[100000]{};
  clutch::Vec4<float> res{1.0f, 1.0f, 1.0f, 1.0f};
  for (auto _ : state)
    for(auto& vector : vectors)
      res *= vector;
}

BENCHMARK(BM_Vec4SSEMultiplication)->Unit(benchmark::kMicrosecond);

static void BM_Vec4SSEDot(benchmark::State& state) {
  clutch::Vec4<float> vectors[100000]{};
  clutch::Vec4<float> res{1.0f, 1.0f, 1.0f, 1.0f};
  int value = 0;
  for (auto _ : state)
    for(auto& vector : vectors)
      value += clutch::Dot(res,vector);
}

BENCHMARK(BM_Vec4SSEDot)->Unit(benchmark::kMicrosecond);

#if defined(STORAGE_SSE)

static void BM_Vec4SSECross(benchmark::State& state) {
  clutch::Vec4<float> vectors[100000]{};
  clutch::Vec4<float> res{1.0f, 1.0f, 1.0f, 1.0f};
  for (auto _ : state)
    for(auto& vector : vectors)
     res += clutch::Cross(res,vector);
}

BENCHMARK(BM_Vec4SSECross)->Unit(benchmark::kMicrosecond);
#endif

static void BM_Vec4SSEMag(benchmark::State& state) {
  clutch::Vec4<float> vectors[100000]{};
  clutch::Vec4<float> res{1.0f, 1.0f, 1.0f, 1.0f};
  int value = 0;
  for (auto _ : state)
    for(auto& vector : vectors)
      value += clutch::Mag(vector);
}

BENCHMARK(BM_Vec4SSEMag)->Unit(benchmark::kMicrosecond);