#ifndef LEETCODE_LEETCODE_75_GRAPHS_DFS_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_HPP_
#define LEETCODE_LEETCODE_75_GRAPHS_DFS_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_HPP_

// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <vector>
#include <queue>

class ReorderRoutesToMakeAllPathsLeadToTheCityZero {
 public:
  int minReorder(int n, const std::vector<std::vector<int>> &connections) const;
};

#endif
