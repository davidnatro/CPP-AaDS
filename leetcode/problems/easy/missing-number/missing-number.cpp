#include "missing-number.hpp"

int MissingNumber::missingNumber(const std::vector<int>& nums) const {
    int result = 0;
    for (int i = 0; i <= nums.size(); ++i) {
        result ^= i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        result ^= nums[i];
    }

    return result;
}