#include "rotate-array.hpp"

void RotateArray::rotate(std::vector<int>& nums, int k) const {
    if (nums.size() <= 1) {
        return;
    }

    k %= nums.size();
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}