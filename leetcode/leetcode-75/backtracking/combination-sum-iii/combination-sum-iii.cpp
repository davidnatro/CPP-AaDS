#include "combination-sum-iii.hpp"

std::vector<std::vector<int>> CombinationSumIII::combinationSum3(const int k, const int n) const {
  std::vector<std::vector<int>> result;
  std::vector<int> combination;
  dfs(1, k, n, result, combination);
  return result;
}

void CombinationSumIII::dfs(const int index,
                            const int k,
                            const int n,
                            std::vector<std::vector<int>> &result,
                            std::vector<int> &combination) const {
  if (n == 0 && combination.size() == k) {
    result.push_back(combination);
    return;
  }
  for (int i = index; i <= 9; i++) {
    combination.push_back(i);
    dfs(i + 1, k, n - i, result, combination);
    combination.pop_back();
  }
}
