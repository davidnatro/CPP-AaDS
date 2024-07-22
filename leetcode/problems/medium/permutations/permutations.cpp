#include "permutations.hpp"

std::vector<std::vector<int>> Permutations::permute(std::vector<int>& nums) const {
    std::vector<std::vector<int>> result;
    backtrack(nums, result, 0);
    return result;
}

void Permutations::backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result,
                             int position) const {
    if (position == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = position; i < nums.size(); ++i) {
        std::swap(nums[position], nums[i]);
        backtrack(nums, result, position + 1);
        std::swap(nums[position], nums[i]);
    }
}