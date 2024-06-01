#ifndef LEETCODE_PROBLEMS_MEDIUM_SUBARRAY_SUM_EQUALS_K_SUBARRAY_SUM_EQUALS_K_HPP_
#define LEETCODE_PROBLEMS_MEDIUM_SUBARRAY_SUM_EQUALS_K_SUBARRAY_SUM_EQUALS_K_HPP_

// https://leetcode.com/problems/subarray-sum-equals-k/

#include <vector>
#include <unordered_map>

class SubarraySumEqualsK {
 public:
  int subarraySum(const std::vector<int> &nums, const int k) const;

  int bruteForce(const std::vector<int> &nums, const int k) const;
};

#endif
