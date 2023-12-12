#include "../headers/3-sum-closest.h"

int ThreeSumClosest::threeSumClosest(std::vector<int> &nums, int target) {
    int result = INT32_MAX;
    int previous_subtraction = INT32_MAX;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return sum;
            } else if (sum > target) {
                right -= 1;
            } else {
                left += 1;
            }

            int subtraction = abs(sum - target);
            if (subtraction < previous_subtraction) {
                result = sum;
                previous_subtraction = subtraction;
            }
        }
    }

    return result;
}