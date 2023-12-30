#include "longest-subarray-of-ones-after-deleting-one-element.h"

int LongestSubarrayOfOnesAfterDeletingOneElement::longestSubarray(
    const std::vector<int> &nums) const {
    int i = 0;
    int j = 0;
    int k = 1;

    while (j < nums.size()) {
        if (nums[j] == 0) {
            k -= 1;
        }

        if (k < 0) {
            if (nums[i] == 0) {
                k += 1;
            }
            i += 1;
        }
        j += 1;
    }

    return j - i - 1;
}
