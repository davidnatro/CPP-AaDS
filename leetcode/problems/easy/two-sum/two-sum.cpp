#include "two-sum.h"

std::vector<int> TwoSum::twoSum(std::vector<int> &nums, int target) {
    std::map<int, int> map;

    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        int j = target - nums[i];
        if (map.count(j) && map[j] != i) {
            return std::vector<int>{map[j], i};
        }
    }

    return std::vector<int>{};
}