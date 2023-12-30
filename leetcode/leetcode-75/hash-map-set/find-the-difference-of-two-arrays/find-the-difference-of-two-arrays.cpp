#include "find-the-difference-of-two-arrays.h"

std::vector<std::vector<int>> FindTheDifferenceOfTwoArrays::findDifference(
    const std::vector<int> &nums1, const std::vector<int> &nums2) const {
    std::vector<int> result1;
    std::vector<int> result2;

    std::unordered_set<int> elements;
    for (const int element : nums2) {
        elements.insert(element);
    }
    for (const int element : nums1) {
        if (!elements.count(element)) {
            result1.emplace_back(element);
            elements.insert(element);
        }
    }

    elements.clear();

    for (const int element : nums1) {
        elements.insert(element);
    }
    for (const int element : nums2) {
        if (!elements.count(element)) {
            result2.emplace_back(element);
            elements.insert(element);
        }
    }

    return std::vector{result1, result2};
}
