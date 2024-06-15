#ifndef LEETCODE_PROBLEMS_HARD_IPO_IPO_HPP_
#define LEETCODE_PROBLEMS_HARD_IPO_IPO_HPP_

// https://leetcode.com/problems/ipo/

#include <queue>
#include <vector>

class IPO {
 public:
  int findMaximizedCapital(int projects,
                           int initial_capital,
                           const std::vector<int> &profits,
                           const std::vector<int> &capital) const;
};

#endif
