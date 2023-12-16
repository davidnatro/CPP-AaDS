#include "../headers/next-permutation.h"

void NextPermutation::nextPermutation(std::vector<int> &nums) {
    for (int i = nums.size() - 1; i > 0; --i) {
        if (nums[i] > nums[i - 1]) {
            int swap_with = i;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] > nums[i - 1]) {
                    swap_with = j;
                } else {
                    break;
                }
            }
            std::swap(nums[i - 1], nums[swap_with]);
            std::reverse(nums.begin() + i, nums.end());
            return;
        }
    }

    std::reverse(nums.begin(), nums.end());
}