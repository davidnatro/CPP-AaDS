#include "range-sum-of-sorted-subarray-sums.hpp"

int RangeSumOfSortedSubarraySums::rangeSum(const std::vector<int>& nums, int n, int left,
                                           int right) const {
    const int range_size = n * (n + 1) / 2;
    std::vector<int> range(range_size);
    int index = 0;
    int index_begin = 0;
    range[index] = nums[0];
    for (int i = 0; i < range_size; ++i) {
        if (index == index_begin) {
            range[i] = nums[index];
        } else {
            range[i] = nums[index] + range[i - 1];
        }

        index += 1;
        if (index == n) {
            index_begin += 1;
            index = index_begin;
        }
    }

    std::sort(range.begin(), range.end());

    constexpr int mod = 1000000007;
    int result = 0;
    for (int i = left - 1; i < right; ++i) {
        result = (result % mod) + (range[i] % mod);
    }

    return result;
}