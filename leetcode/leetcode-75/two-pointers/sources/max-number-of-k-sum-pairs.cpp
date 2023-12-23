#include "../headers/max-number-of-k-sum-pairs.h"

int MaxNumberOfKSumPairs::maxOperations(const std::vector<int> &nums, int k) const {
    std::vector<int> data(nums);
    std::sort(data.begin(), data.end());

    int count = 0;
    int left = 0;
    int right = nums.size() - 1;

    int target;
    while (left < right) {
        target = data[left] + data[right];
        if (target == k) {
            count += 1;
            left += 1;
            right -= 1;
        } else if (target < k) {
            left += 1;
        } else {
            right -= 1;
        }
    }

    return count;
}
