#include "number-of-recent-calls.h"

NumberOfRecentCalls::NumberOfRecentCalls() {
}

int NumberOfRecentCalls::ping(int t) {
    calls_.push(t);

    int front = calls_.front();
    while (!calls_.empty() && (front < getLowerBound(t) || front > getUpperBound(t))) {
        calls_.pop();
        front = calls_.front();
    }

    return calls_.size();
}

int NumberOfRecentCalls::getUpperBound(int t) const {
    return t;
}

int NumberOfRecentCalls::getLowerBound(int t) const {
    return t - 3000;
}
