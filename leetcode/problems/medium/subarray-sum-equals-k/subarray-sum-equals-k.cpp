#include "subarray-sum-equals-k.hpp"

int SubarraySumEqualsK::subarraySum(const std::vector<int> &nums, const int k) const {
  std::unordered_map<int, int> map;
  map[0] = 1;

  int sum = 0;
  int result = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int remove = sum - k;
    result += map[remove];
    map[sum] += 1;
  }

  return result;
}

int SubarraySumEqualsK::bruteForce(const std::vector<int> &nums, const int k) const {
  int result = 0;

  int sum;
  for (int i = 0; i < nums.size(); ++i) {
    sum = 0;
    int j = i;
    while (j < nums.size()) {
      sum += nums[j];
      if (sum == k) {
        result += 1;
      }
      j += 1;
    }
  }

  return result;
}
