#ifndef LEETCODE_LEETCODE_75_GRAPH_BFS_ROTTING_ORANGES_ROTTING_ORANGES_HPP_
#define LEETCODE_LEETCODE_75_GRAPH_BFS_ROTTING_ORANGES_ROTTING_ORANGES_HPP_

// https://leetcode.com/problems/rotting-oranges/

#include <queue>
#include <vector>

class RottingOranges {
 public:
  int orangesRotting(const std::vector<std::vector<int>> &grid) const;

 private:
  bool isFresh(const int orange) const;

  bool isRotten(const int orange) const;
};

#endif
