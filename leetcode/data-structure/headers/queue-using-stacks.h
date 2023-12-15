#ifndef LEETCODE_DATA_STRUCTURE_HEADERS_QUEUE_USING_STACKS_H_
#define LEETCODE_DATA_STRUCTURE_HEADERS_QUEUE_USING_STACKS_H_

// https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>

class QueueUsingStacks {
public:
    QueueUsingStacks();

    void push(int x);

    int pop();

    int peek();

    bool empty();

private:
    void transfer_data();

    std::stack<int> main_stack_;
    std::stack<int> secondary_stack_;
};

#endif
