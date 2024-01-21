#include "3-sum.h"

std::vector<std::vector<int>> ThreeSum::threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int64_t sum = static_cast<int64_t>(nums[i]) + static_cast<int64_t>(nums[left]) +
                          static_cast<int64_t>(nums[right]);
            if (sum == 0) {
                std::vector<int> subset{nums[i], nums[left], nums[right]};
                result.emplace_back(subset);
                while (left < right && nums[left] == subset[1]) {
                    left += 1;
                }
                while (left < right && nums[right] == subset[2]) {
                    right -= 1;
                }
            } else if (sum < 0) {
                left += 1;
            } else {
                right -= 1;
            }
        }
    }

    return result;
}
