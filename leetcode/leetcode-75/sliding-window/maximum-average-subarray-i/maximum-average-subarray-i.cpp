#include "maximum-average-subarray-i.h"

double MaximumAverageSubArrayI::findMaxAverage(const std::vector<int> &nums, int k) {
    if (nums.empty()) {
        return 0;
    }

    double max;
    double target = 0;

    for (int i = 0; i < k; ++i) {
        target += nums[i];
    }
    target /= k;
    max = target;

    for (int i = 1; i <= nums.size() - k; ++i) {
        target *= k;
        target -= nums[i - 1];
        target += nums[i + k - 1];
        target /= k;

        if (target > max) {
            max = target;
        }
    }

    return max;
}
