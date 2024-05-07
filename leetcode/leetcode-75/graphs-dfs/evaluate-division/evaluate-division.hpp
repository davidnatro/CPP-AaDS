#ifndef LEETCODE_LEETCODE_75_GRAPHS_DFS_EVALUATE_DIVISION_EVALUATE_DIVISION_HPP_
#define LEETCODE_LEETCODE_75_GRAPHS_DFS_EVALUATE_DIVISION_EVALUATE_DIVISION_HPP_

// https://leetcode.com/problems/evaluate-division/

#include <map>
#include <vector>
#include <queue>
#include <string>

class EvaluateDivision {
 public:
  std::vector<double> calcEquation(const std::vector<std::vector<std::string>> &equations,
                                   const std::vector<double> &values,
                                   const std::vector<std::vector<std::string>> &queries) const;
};

#endif
