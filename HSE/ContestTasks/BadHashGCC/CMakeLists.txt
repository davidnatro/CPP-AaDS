cmake_minimum_required(VERSION 3.24)
project(BadHashGCC)

set(CMAKE_CXX_STANDARD 17)

add_executable(BadHashGCC main.cpp StringGenerator.cpp StringGenerator.h)
