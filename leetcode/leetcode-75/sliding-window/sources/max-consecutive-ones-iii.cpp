#include "../headers/max-consecutive-ones-iii.h"

int MaxConsecutiveOnesIII::longestOnes(const std::vector<int> &nums, int k) const {
    int i = 0;
    int j = 0;

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

    return j - i;
}
