#include "../headers/intersection-of-two-arrays.h"

std::vector<int> IntersectionOfTwoArrays::intersection(std::vector<int> &nums1,
                                                       std::vector<int> &nums2) {
    std::set<int> set;
    std::vector<int> result;

    for (const int element : nums1) {
        set.insert(element);
    }

    for (const int element : nums2) {
        if (set.count(element)) {
            result.emplace_back(set.extract(element).value());
        }
    }

    return result;
}