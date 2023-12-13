#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H_

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>

class FindFirstAndLastPositionOfElementInSortedArray {
public:
    std::vector<int> searchRange(const std::vector<int> &nums, int target);

private:
    int binarySearch(const std::vector<int> &nums, int target);
};

#endif
