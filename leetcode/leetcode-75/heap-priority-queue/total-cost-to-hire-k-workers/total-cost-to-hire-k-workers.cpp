#include "total-cost-to-hire-k-workers.hpp"

int64_t TotalCostToHireKWorkers::totalCost(const std::vector<int> &costs,
                                           const int k,
                                           const int candidates) const {
  int64_t result = 0;

  int left_index = candidates;
  int right_index = costs.size() - candidates - 1;

  std::priority_queue<int, std::vector<int>, std::greater<int>> left_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> right_heap;

  for (int i = 0; i < candidates; ++i) {
    left_heap.push(costs[i]);
  }

  for (int i = std::max(left_index, right_index + 1); i < costs.size(); ++i) {
    right_heap.push(costs[i]);
  }

  for (int i = 0; i < k; ++i) {
    int left = left_heap.empty() ? INT32_MAX : left_heap.top();
    int right = right_heap.empty() ? INT32_MAX : right_heap.top();

    if (left <= right) {
      left_heap.pop();
      result += left;

      if (left_index <= right_index) {
        left_heap.push(costs[left_index]);
        left_index += 1;
      }
    } else {
      right_heap.pop();
      result += right;

      if (right_index >= left_index) {
        right_heap.push(costs[right_index]);
        right_index -= 1;
      }
    }
  }

  return result;
}
