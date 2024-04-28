#ifndef LEETCODE_LEETCODE_75_GRAPHS_DFS_NUMBER_OF_PROVINCES_NUMBER_OF_PROVINCES_HPP_
#define LEETCODE_LEETCODE_75_GRAPHS_DFS_NUMBER_OF_PROVINCES_NUMBER_OF_PROVINCES_HPP_

// https://leetcode.com/problems/number-of-provinces/

#include <vector>
#include <queue>

class NumberOfProvinces {
 public:
  int findCircleNum(const std::vector<std::vector<int>> &is_connected) const;
};

#endif
