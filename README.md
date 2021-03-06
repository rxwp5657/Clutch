# Clutch
## Why another SIMD Library?
First of all, this library doesn't aim to be a replacement for 
libraries like  **glm**. However, its main objectives are: 
1. Show/Teach "tricks" of SIMD development that can be hard to get when reading pro libraries such as glm.
2. Show/Teach concepts of SIMD levelopment
3. Show/Teach SIMD algorithms for linear algebra operations (Vector-Vector multiplication, Matrix-Vector multiplication).
## Observations
SIMD development is hard and knowing everything needed to make it work at is best can be obscure (information is hard to find), here are some concepts to take into account when developing a SIMD library:
1. The architecture: SIMD instruction sets (SSEx, MMX, AVX, etc.) are processor dependent and, development with SIMD a specific architecture (x86_64, ARM, etc.) should be defined apriori. Thus, this library aims to x86_64 architecture with AVX, SSEx and MMX instruction set.
2. Compilers: compilers may or may not do optimizations that impact SIMD performarmance. Also, the compiler must support SIMD instruction sets.
3. Data Alignment: Data that is loaded to SSE registers should be memory aligned to enable efficient data transfer.
4. Performance: if not implemented correctly (alignment, compiler optimizations, usage of operations like hadd) may impact performance and actually perform worst than a normal implementation (without SIMD).
## Installation
### Requirements
+ C++ 14 compiler.
+ pmmintrin, xmmintrin headers installed (should be included with your computer if your system supports SIMD).
### CMake
In your CMakeLists.txt add:

```c++
    ...
    add_subdirectory(path_to_clutch/clutch)
    include_directories(path_to_clutch/clutch/include)
    target_link_libraries(project_name clutch)
```
## Project Structure
Clutch is a header only project, this is, there are no .cpp files since it is based on templates and inlining, although .inl and #include directives could be used, all code refering each data type is defiened on its own header so, no dependency jumping is required thus, making it easier to understand.

```
├── CMakeLists.txt
├── README.md
├── benchmarks (Benchmarking code)
│   ├── CMakeLists.txt
│   ├── main.cpp
│   ├── mat4_benchmark.cpp
│   └── vec4_benchmark.cpp
│  
├── include (Headers of the project, all self contained)
│   ├── commons.hpp
│   ├── intrinsics.hpp
│   ├── lookat.hpp
│   ├── mat2.hpp
│   ├── mat3.hpp
│   ├── mat4.hpp
│   ├── projections.hpp
│   ├── qualifier.hpp
│   ├── transforms.hpp
│   ├── vec2.hpp
│   ├── vec3.hpp
│   └── vec4.hpp
├── lib (Dependencies of the project, they are only needed for benchmarking and testing)
│   ├── benchmark
│   └── gtest
└── test (Unit testing)
    ├── CMakeLists.txt
    ├── lookat_test.cpp
    ├── main.cpp
    ├── mat2_test.cpp
    ├── mat3_test.cpp
    ├── mat4_test.cpp
    ├── vec2_test.cpp
    ├── vec3_test.cpp
    └── vec4_test.cpp
```
## Usage
Just import the data structures you want to use. For example, if you want to use a Vec4 and a rotation throuh the Z axis you do:
```c++
... //other includes
#include <vec4.hpp>
#include <transforms.hpp>
#include <commons.hpp>

int main(int argc, char *argv[])
{
    clutch::Vec4<float> a{1.0f, 2.0f, 3.0f, 1.0};
    auto transformed_v = clutch::RotateZ(clutch::PI / 4) * a;
    ...
}
```

### OpenGL
Clutch can interoperate with OpenGL, here is a simple example:

```c++
... //other includes 
#define  GLEW_STATIC
#include <vec2.hpp>
#include <transforms.hpp>
#include <commons.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[])
{
    ... // context and window creation and, shader compilation and linkage...


    // Define the vertices of a triangle

    const clutch::Vec2<float> vertices[]{
          clutch::Vec2<float>{0.0f,  0.5f},
          clutch::Vec2<float>{0.5f, -0.5f},
          clutch::Vec2<float>{-0.5f, -0.5f}  
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Load triangle vertex data to GPU

    GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(clutch::Vec2<float>), &vertices[0], GL_STATIC_DRAW);

    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

    ... 
    // render loop, input handling and window management
}
```
Result: 

![Triangle](/docs/triangle.png)

With transform:
```c++
... // includes from example

int main(int argc, char *argv[])
{
    ... // previous snippet

    GLint model    = glGetUniformLocation(shaderProgram, "model");
    auto transform = clutch::RotateZ(clutch::PI / 4);
    glUniformMatrix4fv(model, 1, GL_FALSE, clutch::ValuePtr(transform))

    ... 
    // render loop, input handling and window management
}

```
Result:

![Transforms](/docs/transform.png)

Look-at matrix and perspective projection for camera simulation:

```c++
... // includes from example
#include <projections.hpp>
#include <lookat.hpp>

int main(int argc, char *argv[])
{
    ... // previous snippet

    clutch::Vec4<float> posititon{0.0f, 0.0f, 5.0f, 1.0};
    clutch::Vec4<float> target{0.0f, 0.0f, 0.0f, 1.0};
    clutch::Vec4<float> up{0.0f, 1.0f, 0.0f};

    auto view = clutch::LookAt(posititon,target,up);
    auto proj = clutch::Perspective((45.0f * clutch::PI) / 180, 800.0f / 600.0f, 1.0f, 100.0f);

    // load transforms to shader to make MVP;

    GLint view_gl  = glGetUniformLocation(shaderProgram, "V");
    glUniformMatrix4fv(model, 1, GL_FALSE, clutch::ValuePtr(view))

    GLint proj_gl  = glGetUniformLocation(shaderProgram, "P");
    glUniformMatrix4fv(model, 1, GL_FALSE, clutch::ValuePtr(proj))

    ... 
    // render loop, input handling and window management
}

```
Result: 

![Transforms](/docs/monkey.gif)

## Benchmarks
Now, SIMD is about performance so, some benchmarks were run with the following specifications:
+ **library**: Google Benchmark.
+ **CPU**: 1.4 GHz Intel Core i5 8th gen.
+ **RAM**: 8gb 2133MHz.
+ **Compiler**: AppleClang.
+ **Compiler Version**: 10.0.1.10010046.
+ **Number of operands**: 100,000 vectors and matrices were used for the operations.
+ **Iterations**: iterations.
+ **SIMD enabled and disabled**.

### Benchmark Results SIMD Disabled

| Benchmark Name | Mean Time | Median Time | Mean CPU | Median CPU |
| :------------- | :-------: | :---------: | :------: | :--------: |
| Mat4 Addition  | 1085 ns   | 1084 ns     | 1083 ns  | 1082 ns    |
| Mat4 Substraction   | 1075 ns    | 1073 ns      | 1073 ns   | 1072 ns   |
| Mat4 Multiplication | 755849 ns  | 753052 ns    | 754114 ns | 751472 ns |
| Mat4 Member Multiplication  | 963014 ns  | 956425 ns | 959876 ns | 955453 ns |
| Mat4 Transpose | 1083 ns    | 1084 ns    | 1081 ns   | 1082 ns |

| Benchmark Name | Mean Time | Median Time | Mean CPU | Median CPU |
| :------------- | :-------: | :---------: | :------: | :--------: |
| Vec4 Addition  | 1080 ns   | 1077 ns     | 1078 ns  | 1076 ns    |
| Vec4 Substraction   | 1086 ns | 1083 ns  | 1083 ns  | 1081 ns    |
| Vec4 Multiplication | 1059 ns | 1055 ns  | 1058 ns  | 1055 ns    |
| Vec4 Dot Product    | 1076 ns | 1072 ns  | 1074 ns  | 1071 ns    |
| Vec4 Magnitude      | 1079 ns | 1080 ns  | 1078 ns  | 1078 ns    |

### Benchmark Results SIMD Enabled

| Benchmark Name | Mean Time | Median Time | Mean CPU | Median CPU |
| :------------- | :-------: | :---------: | :------: | :--------: |
| Mat4 Addition  | 1053 ns   | 1053 ns     | 1053 ns  | 1053 ns    |
| Mat4 Substraction   | 1055 ns  | 1052 ns | 1055 ns  | 1052 ns    |
| Mat4 Multiplication | 1067 ns  | 1057 ns | 1066 ns  | 1057 ns    |
| Mat4 Member Multiplication  | 1062 ns    | 1053 ns  | 1061 ns | 1052 ns |
| Mat4 Transpose | 1076 ns    | 1074 ns    | 1075 ns  | 1072 ns |
| Mat4 Inverse   | 2563755 ns | 2557643 ns | 2559860 ns | 2555468 ns|

| Benchmark Name | Mean Time | Median Time | Mean CPU | Median CPU |
| :------------- | :-------: | :---------: | :------: | :--------: |
| Vec4 Addition  | 1063 ns   | 1054 ns     | 1062 ns  | 1054 ns    |
| Vec4 Substraction   | 1080 ns | 1076 ns  | 1078 ns  | 1075 ns    |
| Vec4 Multiplication | 1074 ns | 1062 ns  | 1072 ns  | 1062 ns    |
| Vec4 Dot Product    | 1073 ns | 1058 ns  | 1071 ns  | 1057 ns    |
| Vec4 Cross Product  | 1076 ns | 1064 ns  | 1074 ns  | 1063 ns    |
| Vec4 Magnitude      | 1068 ns | 1055 ns  | 1067 ns  | 1055 ns    |

### Benchmark Results Discussion
As you can see, benchmarks results proved that SIMD operations overall improve from the normal template operations but, most of the improvements are not quite significant. For example: vector addition had an improvement of the 9.5% for mean time, 3.3% for meadian time, 1.5% for mean CPU and 2.1% for median CPU time. In this case, there may be a few reasons for this to be happening: data structures are not being alinged or, SIMD perform better when operations are done in batch like Matrix - Matrix multiplication. On the other hand and, as a result of great improvement, Matrix - Matrix multiplication showed an improvement of the 99.8% for mean time, 99.8% for the median time, 98.56% for mean CPU and 99.8% for median CPU time.

In conclusion, SIMD proved to have improvements against template implementation but not all cases were significant. Thus, benchmarks need to be revised as well as implemtation, maybe trick 1. (uniforms) are not helping or maybe alignment needs to be checked. Also, matrix inversion algorithm needs to be revised beacuase performance was at its worst. 

## TODO
[ ] Union vs load and unload during SIMD function call.  
[ ] Check alignment of data structrues (this may be holding off performance).   
[ ] Implement promotion and operations between Vec(N - 1) to Vec(N) and Mat(N-1) to Mat(N).  
[ ] Check structure alignments.




