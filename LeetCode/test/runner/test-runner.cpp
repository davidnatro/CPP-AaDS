#include "test-runner.h"

template <typename T>
TestRunner<T>::TestRunner(const std::vector<T> &test_cases, const std::vector<T> &test_results) {
    if (test_cases.size() != test_results.size()) {
        throw std::runtime_error("test cases and test results cannot be of different sizes");
    }

    this->test_cases_ = test_cases;
    this->test_results_ = test_results;

    test_cases_size_ = test_cases.size();
}

template <typename T>
void TestRunner<T>::run(T (*func)(const T &var1)) {
    auto start = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << "elapsed in: " << nanoseconds << "ns";
}