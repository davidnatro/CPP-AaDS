#include "../headers/intersection-of-two-arrays-ii.h"

std::vector<int> IntersectionOfTwoArraysII::intersect(std::vector<int> &nums1,
                                                         std::vector<int> &nums2) {
    std::map<int, int> map;
    std::vector<int> result;

    for (const int element : nums1) {
        if (map.count(element)) {
            map[element] += 1;
        } else {
            map[element] = 1;
        }
    }

    for (const int element : nums2) {
        if (map[element] > 0) {
            result.emplace_back(element);
            map[element] -= 1;
        }
    }

    return result;
}