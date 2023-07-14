cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Reflection VERSION 0.1.0 LANGUAGES C CXX)

add_executable(test main.cpp classes.cpp introspection.cpp)
