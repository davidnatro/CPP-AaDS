#ifndef LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_TOTAL_COST_TO_HIRE_K_WORKERS_TOTAL_COST_TO_HIRE_K_WORKERS_HPP_
#define LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_TOTAL_COST_TO_HIRE_K_WORKERS_TOTAL_COST_TO_HIRE_K_WORKERS_HPP_

// https://leetcode.com/problems/total-cost-to-hire-k-workers/

#include <queue>
#include <vector>

class TotalCostToHireKWorkers {
 public:
  int64_t totalCost(const std::vector<int> &costs, const int k, const int candidates) const;
};

#endif
