cmake_minimum_required (VERSION 2.8)

# Project Name
project (clutch)

set(CMAKE_BUILD_TYPE Release)

#Bring the headers
include_directories(include)

file(GLOB SOURCES "./*.cpp")

add_library(clutch STATIC ${SOURCES})

install(TARGETS clutch DESTINATION /usr/lib)