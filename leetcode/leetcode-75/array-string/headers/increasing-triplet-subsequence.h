#ifndef LEETCODE_LEETCODE_75_ARRAY_STRING_HEADERS_INCREASING_TRIPLET_SUBSEQUENCE_H_
#define LEETCODE_LEETCODE_75_ARRAY_STRING_HEADERS_INCREASING_TRIPLET_SUBSEQUENCE_H_

#include <vector>
class IncreasingTripletSubsequence {
public:
    bool increasingTriplet(const std::vector<int>& nums) const;

private:
    bool checkLeftTriplet(const std::vector<int> &nums) const;

    bool checkRightTriplet(const std::vector<int> &nums) const;
};

#endif
