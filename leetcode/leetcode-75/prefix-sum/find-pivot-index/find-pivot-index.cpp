#include "find-pivot-index.h"

int FindPivotIndex::pivotIndex(const std::vector<int> &nums) const {
    if (nums.empty()) {
        return -1;
    }

    std::vector<int> prefix_sum(nums.size());

    prefix_sum[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; --i) {
        prefix_sum[i] = nums[i] + prefix_sum[i + 1];
    }

    int left_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        left_sum += nums[i];
        if (left_sum == prefix_sum[i]) {
            return i;
        }
    }

    return -1;
}
