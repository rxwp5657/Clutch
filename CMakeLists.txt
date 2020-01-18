cmake_minimum_required(VERSION 3.12)

# Project Name
project("clutch" VERSION 1.0.1
            HOMEPAGE_URL "https://github.com/rxwp5657/Clutch.git")

set(CMAKE_BUILD_TYPE Release)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commons.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/lookat.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/mat2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/mat3.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/mat4.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/projections.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/transforms.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/vec2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/vec3.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/vec4.hpp
    )

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_14)

target_include_directories(${PROJECT_NAME} INTERFACE include/)
target_link_libraries(${PROJECT_NAME})
