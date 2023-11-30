#ifndef LEETCODE_TEST_RUNNER_TEST_RUNNER_H_
#define LEETCODE_TEST_RUNNER_TEST_RUNNER_H_

#include <chrono>
#include <iostream>
#include <vector>

#include "i-test-runner.h"

template <typename T>
class TestRunner : public ITestRunner<T> {
private:
    size_t test_cases_size_;

    std::vector<T> test_cases_;
    std::vector<T> test_results_;

public:
    size_t getTestsSize() const {
        return test_cases_size_;
    }

    const std::vector<T> &getTestCases() const {
        return test_cases_;
    }

    const std::vector<T> &getTestResults() const {
        return test_results_;
    }

    virtual void run() override {
    }

    virtual ~TestRunner() override{};
};

#endif
