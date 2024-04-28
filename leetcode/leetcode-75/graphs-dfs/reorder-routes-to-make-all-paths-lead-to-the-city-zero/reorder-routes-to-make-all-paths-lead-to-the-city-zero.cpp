#include "reorder-routes-to-make-all-paths-lead-to-the-city-zero.hpp"

int ReorderRoutesToMakeAllPathsLeadToTheCityZero::minReorder(int n,
                                                             const std::vector<std::vector<int>> &connections) const {
  std::vector<std::vector<std::vector<int>>> data(n);
  for (const std::vector<int> &connection : connections) {
    data[connection[0]].emplace_back(std::vector<int>{connection[1], 1});
    data[connection[1]].emplace_back(std::vector<int>{connection[0], 0});
  }

  std::vector<bool> visited(n, false);
  std::queue<int> roads;
  roads.push(0);
  visited[0] = true;
  int count = 0;

  while (!roads.empty()) {
    int road = roads.front();
    roads.pop();

    for (const std::vector<int> &city : data[road]) {
      int neighbour = city[0];
      int sign = city[1];

      if (!visited[neighbour]) {
        count += sign;
        visited[neighbour] = true;
        roads.push(neighbour);
      }
    }
  }

  return count;
}