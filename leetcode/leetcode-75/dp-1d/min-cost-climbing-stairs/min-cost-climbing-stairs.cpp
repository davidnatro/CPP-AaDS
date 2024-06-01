#include "min-cost-climbing-stairs.hpp"

int MinCostClimbingStairs::minCostClimbingStairs(const std::vector<int> &cost) const {
  std::vector<int> dp(cost.size());

  dp[0] = cost[0];
  dp[1] = cost[1];

  for (int i = 2; i < cost.size(); ++i) {
    dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
  }

  return std::min(dp[dp.size() - 1], dp[dp.size() - 2]);
}
