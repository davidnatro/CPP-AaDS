#include "evaluate-division.hpp"

std::vector<double> EvaluateDivision::calcEquation(const std::vector<std::vector<std::string>> &equations,
                                                   const std::vector<double> &values,
                                                   const std::vector<std::vector<std::string>> &queries) const {
  std::vector<double> results;
  std::map<std::string, std::vector<std::pair<std::string, double>>> calculations;
  for (int i = 0; i < equations.size(); ++i) {
    calculations[equations[i][0]].emplace_back(std::make_pair(equations[i][1], values[i]));
    calculations[equations[i][1]].emplace_back(std::make_pair(equations[i][0], 1 / values[i]));
  }

  for (int i = 0; i < queries.size(); ++i) {
    std::string numerator = queries[i][0];
    std::string denominator = queries[i][1];

    if (!calculations.count(numerator) || !calculations.count(denominator)) {
      results.emplace_back(-1.0);
      continue;
    }

    std::queue<std::pair<std::string, double>> bfs;
    bfs.push(std::make_pair(numerator, 1));
    std::map<std::string, bool> visited;
    bool pathFound = false;

    while (!bfs.empty()) {
      std::pair<std::string, double> element = bfs.front();
      bfs.pop();

      if (element.first == denominator) {
        results.emplace_back(element.second);
        pathFound = true;
        break;
      }

      visited[element.first] = true;

      for (const auto &neighbour : calculations[element.first]) {
        if (!visited[neighbour.first]) {
          bfs.push(std::make_pair(neighbour.first, element.second * neighbour.second));
        }
      }
    }

    if (!pathFound) {
      results.emplace_back(-1.0);
    }
  }

  return results;
}
