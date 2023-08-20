cmake_minimum_required(VERSION 3.25)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

set(CMAKE_CXX_FLAGS_UBSAN "-g -fsanitize=undefined"
        CACHE STRING "Compiler flags in ubsan build"
        FORCE)

add_executable(LeetCode main.cpp
        problems/medium/headers/clone-graph.h
        problems/medium/sources/clone-graph.cpp)