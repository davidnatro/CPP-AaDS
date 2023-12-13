#include "../headers/find-duplicates-in-an-array.h"

std::vector<int> FindDuplicatesInAnArray::findDuplicates(const std::vector<int> &nums) {
    std::vector<int> result;
    int duplicates[nums.size()];

    for (int i = 0; i < nums.size(); ++i) {
        duplicates[i] = 0;
    }

    for (int i = 0; i < nums.size(); ++i) {
        duplicates[nums[i] - 1] += 1;
        if (duplicates[nums[i] - 1] > 1) {
            result.emplace_back(nums[i]);
        }
    }

    return result;
}