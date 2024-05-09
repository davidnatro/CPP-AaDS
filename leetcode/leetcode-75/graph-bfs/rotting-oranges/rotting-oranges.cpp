#include "rotting-oranges.hpp"

int RottingOranges::orangesRotting(const std::vector<std::vector<int>> &grid) const {
  int fresh_oranges = 0;
  int rows = grid.size();
  int columns = grid[0].size();

  int minutes = 0;
  int result = INT_MAX;
  std::queue<std::pair<int, int>> rotten;
  std::vector<std::vector<int>> visited(grid.size(), std::vector<int>(grid[0].size(), false));

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (isRotten(grid[i][j])) {
        visited[i][j] = true;
        rotten.push(std::make_pair(i, j));
      } else if (isFresh(grid[i][j])) {
        fresh_oranges += 1;
      }
    }
  }

  if (fresh_oranges == 0) {
    return 0;
  }

  while (!rotten.empty()) {
    minutes += 1;
    int size = rotten.size();
    while (size--) {
      std::pair<int, int> coordinates = rotten.front();
      rotten.pop();

      int row = coordinates.first;
      int column = coordinates.second;

      if (row - 1 >= 0 && !visited[row - 1][column] && isFresh(grid[row - 1][column])) {
        fresh_oranges -= 1;
        visited[row - 1][column] = true;
        rotten.push({row - 1, column});
      }

      if (column - 1 >= 0 && !visited[row][column - 1] && isFresh(grid[row][column - 1])) {
        fresh_oranges -= 1;
        visited[row][column - 1] = true;
        rotten.push({row, column - 1});
      }

      if (column + 1 < columns && !visited[row][column + 1] && isFresh(grid[row][column + 1])) {
        fresh_oranges -= 1;
        visited[row][column + 1] = true;
        rotten.push({row, column + 1});
      }

      if (row + 1 < rows && !visited[row + 1][column] && isFresh(grid[row + 1][column])) {
        fresh_oranges -= 1;
        visited[row + 1][column] = true;
        rotten.push({row + 1, column});
      }
    }

    if (minutes < result && fresh_oranges == 0) {
      result = minutes;
    }
  }

  return result == INT_MAX ? -1 : result;
}

bool RottingOranges::isFresh(const int orange) const {
  return orange == 1;
}

bool RottingOranges::isRotten(const int orange) const {
  return orange == 2;
}
