#ifndef LEETCODE_LEETCODE_75_GRAPH_BFS_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_HPP_
#define LEETCODE_LEETCODE_75_GRAPH_BFS_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_HPP_

// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include <vector>
#include <queue>

class NearestExitFromEntranceInMaze {
 public:
  int nearestExit(const std::vector<std::vector<char>> &maze,
                  const std::vector<int> &entrance) const;

 private:
  bool isWall(const char symbol) const;
};

#endif
