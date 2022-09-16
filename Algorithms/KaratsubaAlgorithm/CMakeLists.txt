cmake_minimum_required(VERSION 3.19)
project(KaratsubaAlgorithm)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

set(CMAKE_CXX_FLAGS_UBSAN "-g -fsanitize=undefined"
        CACHE STRING "Compiler flags in ubsan build"
        FORCE)

add_executable(KaratsubaAlgorithm main.cpp)