#ifndef LEETCODE_LEETCODE_75_BACKTRACKING_COMBINATION_SUM_III_COMBINATION_SUM_III_HPP_
#define LEETCODE_LEETCODE_75_BACKTRACKING_COMBINATION_SUM_III_COMBINATION_SUM_III_HPP_

// https://leetcode.com/problems/combination-sum-iii/

#include <vector>

class CombinationSumIII {
 public:
  std::vector<std::vector<int>> combinationSum3(const int k, const int n) const;

 private:
  void dfs(const int index,
           const int k,
           const int n,
           std::vector<std::vector<int>> &result,
           std::vector<int> &combination) const;
};

#endif
