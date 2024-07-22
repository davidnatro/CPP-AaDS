#ifndef PERMUTATIONS_HPP
#define PERMUTATIONS_HPP

// https://leetcode.com/problems/permutations/

#include <vector>

class Permutations {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) const;

private:
    std::vector<std::vector<int>> permuteSingle(const std::vector<int>& nums) const;

    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result,
                   int position) const;
};

#endif