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

### OpenGl
Clutch can interoperate with OpenGl, here is a simple example:

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

    auto view = clutch::LookAt(from,to,up);
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

