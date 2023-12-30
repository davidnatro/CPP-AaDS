#ifndef LEETCODE_LEETCODE_75_HASH_MAP_SET_FIND_THE_DIFFERENCE_OF_TWO_ARRAYS_FIND_THE_DIFFERENCE_OF_TWO_ARRAYS_H_
#define LEETCODE_LEETCODE_75_HASH_MAP_SET_FIND_THE_DIFFERENCE_OF_TWO_ARRAYS_FIND_THE_DIFFERENCE_OF_TWO_ARRAYS_H_

// https://leetcode.com/problems/find-the-difference-of-two-arrays/

#include <unordered_set>
#include <vector>

class FindTheDifferenceOfTwoArrays {

public:
    std::vector<std::vector<int>> findDifference(const std::vector<int>& nums1,
                                                 const std::vector<int>& nums2) const;
};

#endif
