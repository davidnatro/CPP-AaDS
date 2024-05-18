#include "house-robber.hpp"

int HouseRobber::rob(const std::vector<int> &nums) const {
  if (nums.size() == 1) {
    return nums[0];
  }

  std::vector<int> dp(nums.size());

  dp[0] = nums[0];
  dp[1] = (nums.size() == 1) ? nums[0] : std::max(nums[0], nums[1]);

  for (int i = 2; i < nums.size(); ++i) {
    dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
  }

  return std::max(dp[dp.size() - 1], dp[dp.size() - 2]);
}
