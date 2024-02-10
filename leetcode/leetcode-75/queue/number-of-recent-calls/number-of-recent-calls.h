#ifndef LEETCODE_LEETCODE_75_QUEUE_NUMBER_OF_RECENT_CALLS_NUMBER_OF_RECENT_CALLS_H_
#define LEETCODE_LEETCODE_75_QUEUE_NUMBER_OF_RECENT_CALLS_NUMBER_OF_RECENT_CALLS_H_

// https://leetcode.com/problems/number-of-recent-calls/

#include <queue>

class NumberOfRecentCalls {
public:
    NumberOfRecentCalls();

    int ping(int t);

private:
    std::queue<int> calls_;

    int getUpperBound(int t) const;

    int getLowerBound(int t) const;
};

#endif
