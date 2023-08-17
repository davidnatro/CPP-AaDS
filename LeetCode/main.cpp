#include <iostream>
#include <vector>

#include "problems/easy/headers/intersection-of-two-arrays-ii.h"
#include "problems/easy/headers/path-sum.h"
#include "problems/medium/headers/longest-palindromic-substring.h"
#include "test/runner/test-runner.h"

int main() {

    //    ITestRunner<int> *test_runner = new TestRunner<int>();
    //
    //    delete test_runner;

    std::vector<int> vec1{4, 9, 5};
    std::vector<int> vec2{9, 4, 9, 8, 4};

    IntersectionOfTwoArraysII intersection_of_two_arrays;
    for (const int element : intersection_of_two_arrays.intersect(vec1, vec2)) {
        std::cout << element << "\t";
    }

    return 0;
}
