#include "sort-array-by-increasing-frequency.hpp"

std::vector<int> SortArrayByIncreasingFrequency::frequencySort(std::vector<int>& nums) const {
    std::map<int, int> frequency;
    for (const int num : nums) {
        frequency[num] += 1;
    }

    std::sort(nums.begin(), nums.end(), [&](const int first, const int second) {
        if (frequency[first] == frequency[second]) {
            return first > second;
        }
        return frequency[first] < frequency[second];
    });

    return nums;
}