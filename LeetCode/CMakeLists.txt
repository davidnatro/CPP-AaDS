cmake_minimum_required(VERSION 3.25)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

set(CMAKE_CXX_FLAGS_UBSAN "-g -fsanitize=undefined"
        CACHE STRING "Compiler flags in ubsan build"
        FORCE)

add_executable(LeetCode main.cpp problems/medium/headers/longest-palindromic-substring.h problems/medium/sources/longest-palindromic-substring.cpp test/runner/i-test-runner.h test/runner/test-runner.h
        problems/easy/headers/path-sum.h
        problems/easy/sources/path-sum.cpp
        problems/easy/headers/same-tree.h
        problems/easy/sources/same-tree.cpp
        problems/easy/headers/symmetric-tree.h
        problems/easy/sources/symmetric-tree.cpp
        problems/easy/headers/ugly-number.h
        problems/easy/sources/ugly-number.cpp)