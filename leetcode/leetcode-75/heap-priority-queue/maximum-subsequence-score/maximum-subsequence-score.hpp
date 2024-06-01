#ifndef LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_MAXIMUM_SUBSEQUENCE_SCORE_MAXIMUM_SUBSEQUENCE_SCORE_HPP_
#define LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_MAXIMUM_SUBSEQUENCE_SCORE_MAXIMUM_SUBSEQUENCE_SCORE_HPP_

// https://leetcode.com/problems/maximum-subsequence-score/

#include <queue>
#include <vector>

class MaximumSubsequenceScore {
 public:
  int64_t maxScore(const std::vector<int> &nums1, const std::vector<int> &nums2, const int k) const;
};

#endif
