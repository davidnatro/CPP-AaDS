#ifndef RANGE_SUM_OF_SORTED_SUBARRAY_SUMS_HPP
#define RANGE_SUM_OF_SORTED_SUBARRAY_SUMS_HPP

// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

#include <vector>

class RangeSumOfSortedSubarraySums {
public:
    int rangeSum(const std::vector<int>& nums, int n, int left, int right) const;
};

#endif