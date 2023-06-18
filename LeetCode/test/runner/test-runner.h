#ifndef LEETCODE_TEST_RUNNER_TEST_RUNNER_H_
#define LEETCODE_TEST_RUNNER_TEST_RUNNER_H_

#include <vector>
#include <chrono>
#include <iostream>

template <typename T>
class TestRunner {
private:
    size_t test_cases_size_;

    std::vector<T> test_cases_;
    std::vector<T> test_results_;

public:

    TestRunner(const std::vector<T> &test_cases, const std::vector<T> &test_results);

    void run(T (*func)(const T &var1));
};

#endif
