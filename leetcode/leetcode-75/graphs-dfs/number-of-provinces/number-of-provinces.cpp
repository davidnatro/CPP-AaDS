#include "number-of-provinces.hpp"

int NumberOfProvinces::findCircleNum(const std::vector<std::vector<int>> &is_connected) const {
  int provinces = 0;
  std::queue<int> cities;
  std::vector<bool> visited(is_connected.size(), false);

  for (int i = 0; i < is_connected.size(); ++i) {
    if (!visited[i]) {
      provinces += 1;
      visited[i] = true;
      cities.push(i);
      while (!cities.empty()) {
        int city = cities.front();
        cities.pop();
        for (int j = 0; j < is_connected[city].size(); ++j) {
          if (!visited[j] && is_connected[city][j] == 1) {
            cities.push(j);
            visited[j] = true;
          }
        }
      }
    }
  }

  return provinces;
}
