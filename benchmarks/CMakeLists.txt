cmake_minimum_required (VERSION 2.8)

# Project Name
project (clutch)

set(CMAKE_CXX_FLAGS "-g -Wall")

add_compile_definitions(STORAGE_SSE)

#Project headers
include_directories(../include/)

#Testing

#Project libraries

file(GLOB T_SOURCES ./*.cpp)

# Add gtest testing framework

add_subdirectory(../lib/gtest gtest_bin_dir)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(../lib/benchmark benchmark_bin_dir)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-DCMAKE_BUILD_TYPE=Release)
include_directories(../lib/benchmark/include)

set(CMAKE_CXX_STANDARD 14)
add_executable(clutch_benchmark ${T_SOURCES})

target_link_libraries(clutch_benchmark gtest benchmark::benchmark)