#include "2-sum.h"

std::vector<int> TwoSum::twoSum(std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                return std::vector<int>{i, j};
            }
        }
    }
    return std::vector<int>{-1, -1};
}