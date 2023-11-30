#include "../headers/StackUsingQueues.h"

StackUsingQueues::StackUsingQueues() {
}

void StackUsingQueues::push(int x) {
    main_queue_.push(x);
}

int StackUsingQueues::pop() {
    int top;
    while (!main_queue_.empty()) {
        top = main_queue_.front();
        main_queue_.pop();
        if (!main_queue_.empty()) {
            secondary_queue_.push(top);
        }
    }

    while (!secondary_queue_.empty()) {
        int temp = secondary_queue_.front();
        secondary_queue_.pop();
        main_queue_.push(temp);
    }

    return top;
}

int StackUsingQueues::top() {
    int top;
    while (!main_queue_.empty()) {
        top = main_queue_.front();
        main_queue_.pop();
        secondary_queue_.push(top);
    }

    while (!secondary_queue_.empty()) {
        int temp = secondary_queue_.front();
        secondary_queue_.pop();
        main_queue_.push(temp);
    }

    return top;
}

bool StackUsingQueues::empty() const {
    return main_queue_.empty();
}