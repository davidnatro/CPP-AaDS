#include "min-stack.hpp"

MinStack::MinStack() {
}

void MinStack::push(int val) {
    if (data_.empty()) {
        data_.push_back(std::make_pair(val, val));
        return;
    }

    if (int previous_min = data_.back().second; previous_min <= val) {
        data_.push_back(std::make_pair(val, previous_min));
    } else {
        data_.push_back(std::make_pair(val, val));
    }
}

void MinStack::pop() {
    data_.pop_back();
}

int MinStack::top() const {
    return data_.back().first;
}


int MinStack::getMin() const {
    return data_.back().second;
}