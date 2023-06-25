#ifndef LEETCODE_TEST_RUNNER_I_TEST_RUNNER_H_
#define LEETCODE_TEST_RUNNER_I_TEST_RUNNER_H_

template <typename T>
class ITestRunner {
public:
    virtual void run() = 0;

    virtual ~ITestRunner(){};
};

#endif
