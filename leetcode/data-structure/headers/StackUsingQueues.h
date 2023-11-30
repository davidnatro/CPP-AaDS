#ifndef LEETCODE_DATA_STRUCTURE_HEADERS_STACKUSINGQUEUES_H_
#define LEETCODE_DATA_STRUCTURE_HEADERS_STACKUSINGQUEUES_H_

// https://leetcode.com/problems/implement-stack-using-queues/

#include <queue>

class StackUsingQueues {
public:
    StackUsingQueues();

    void push(int x);

    int pop();

    int top();

    bool empty() const;

private:
    std::queue<int> main_queue_;
    std::queue<int> secondary_queue_;
};

#endif
