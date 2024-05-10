#include "maximum-subsequence-score.hpp"

int64_t MaximumSubsequenceScore::maxScore(const std::vector<int> &nums1,
                                          const std::vector<int> &nums2,
                                          const int k) const {
  int size = nums1.size();
  std::vector<std::pair<int, int>> pairs;

  for (int i = 0; i < size; ++i) {
    pairs.emplace_back(std::make_pair(nums2[i], nums1[i]));
  }

  std::sort(pairs.begin(), pairs.end(), std::greater<std::pair<int, int>>());

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  int64_t sum = 0;
  int64_t result = 0;
  for (const std::pair<int, int> &pair : pairs) {
    sum += pair.second;
    min_heap.push(pair.second);

    if (min_heap.size() > k) {
      sum -= min_heap.top();
      min_heap.pop();
    }

    if (min_heap.size() == k) {
      result = std::max(result, sum * pair.first);
    }
  }

  return result;
}
