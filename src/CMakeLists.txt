cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Reflection VERSION 0.1.0 LANGUAGES CXX)

add_executable(test main.cpp classes.cpp introspection.cpp)
