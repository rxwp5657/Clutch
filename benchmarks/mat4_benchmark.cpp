#include <benchmark/benchmark.h>
#include <mat4.hpp>

static void BM_Mat4SSEAddition(benchmark::State& state) {
    clutch::Mat4<float> matrices[100000]{};
    clutch::Mat4<float> res{1.0f, 1.0f, 1.0f, 1.0f,
                          2.0f, 2.0f, 2.0f, 2.0f,
                          3.0f, 3.0f, 3.0f, 3.0f,
                          4.0f, 4.0f, 4.0f, 4.0f};
    for (auto _ : state)
        for(auto& matrix : matrices)
            res += matrix;
}

BENCHMARK(BM_Mat4SSEAddition)->Unit(benchmark::kMicrosecond);

static void BM_Mat4SSESubstraction(benchmark::State& state) {
    clutch::Mat4<float> matrices[100000]{};
    clutch::Mat4<float> res{1.0f, 1.0f, 1.0f, 1.0f,
                          2.0f, 2.0f, 2.0f, 2.0f,
                          3.0f, 3.0f, 3.0f, 3.0f,
                          4.0f, 4.0f, 4.0f, 4.0f};
    for (auto _ : state)
        for(auto& matrix : matrices)
            res -= matrix;
}

BENCHMARK(BM_Mat4SSESubstraction)->Unit(benchmark::kMicrosecond);

static void BM_Mat4SSEMultiplication(benchmark::State& state) {
    clutch::Mat4<float> matrices[100000]{};
    clutch::Mat4<float> res{1.0f, 1.0f, 1.0f, 1.0f,
                          2.0f, 2.0f, 2.0f, 2.0f,
                          3.0f, 3.0f, 3.0f, 3.0f,
                          4.0f, 4.0f, 4.0f, 4.0f};
    for (auto _ : state)
        for(auto& matrix : matrices)
            res *= matrix;
}

BENCHMARK(BM_Mat4SSEMultiplication)->Unit(benchmark::kMicrosecond);

static void BM_Mat4SSEMultiplicationStar(benchmark::State& state) {
    clutch::Mat4<float> matrices[100000]{};
    clutch::Mat4<float> res{1.0f, 1.0f, 1.0f, 1.0f,
                          2.0f, 2.0f, 2.0f, 2.0f,
                          3.0f, 3.0f, 3.0f, 3.0f,
                          4.0f, 4.0f, 4.0f, 4.0f};
    for (auto _ : state)
        for(auto& matrix : matrices)
            res += matrix * res;
}

BENCHMARK(BM_Mat4SSEMultiplicationStar)->Unit(benchmark::kMicrosecond);

static void BM_Mat4SSETranspose(benchmark::State& state) {
    clutch::Mat4<float> matrices[100000]{};
    clutch::Mat4<float> res{1.0f, 1.0f, 1.0f, 1.0f,
                          2.0f, 2.0f, 2.0f, 2.0f,
                          3.0f, 3.0f, 3.0f, 3.0f,
                          4.0f, 4.0f, 4.0f, 4.0f};
    for (auto _ : state)
        for(auto& matrix : matrices)
            res += clutch::Transpose(matrix);
}

BENCHMARK(BM_Mat4SSETranspose)->Unit(benchmark::kMicrosecond);

static void BM_Mat4Inverse(benchmark::State& state) {
    clutch::Mat4<float> matrices[100000]{};
    clutch::Mat4<float> res{1.0f, 1.0f, 1.0f, 1.0f,
                          2.0f, 2.0f, 2.0f, 2.0f,
                          3.0f, 3.0f, 3.0f, 3.0f,
                          4.0f, 4.0f, 4.0f, 4.0f};
    for (auto _ : state)
        for(auto& matrix : matrices)
            res += clutch::Inverse(matrix);
}

BENCHMARK(BM_Mat4Inverse)->Unit(benchmark::kMicrosecond);