#ifndef MIN_STACK_HPP
#define MIN_STACK_HPP

// https://leetcode.com/problems/min-stack/

#include <list>

class MinStack {
public:
    MinStack();
    void push(int val);
    void pop();
    int top() const;
    int getMin() const;

private:
    std::list<std::pair<int, int>> data_;
};

#endif