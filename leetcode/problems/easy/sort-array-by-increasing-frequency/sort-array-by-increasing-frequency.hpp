#ifndef SORT_ARRAY_BY_INCREASING_FREQUENCY_HPP
#define SORT_ARRAY_BY_INCREASING_FREQUENCY_HPP

// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <map>
#include <vector>

class SortArrayByIncreasingFrequency {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) const;
};

#endif