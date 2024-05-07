#include "nearest-exit-from-entrance-in-maze.hpp"

int NearestExitFromEntranceInMaze::nearestExit(const std::vector<std::vector<char>> &maze,
                                               const std::vector<int> &entrance) const {
  int rows = maze.size();
  int columns = maze[0].size();
  std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
  visited[entrance[0]][entrance[1]] = true;

  std::queue<std::vector<int>> positions;
  positions.push({entrance[0], entrance[1], 0});

  while (!positions.empty()) {
    std::vector<int> position = positions.front();
    positions.pop();

    int row = position[0];
    int column = position[1];
    int steps = position[2];

    if (row == 0 || column == 0 || row == rows - 1 || column == columns - 1) {
      if (row != entrance[0] || column != entrance[1]) {
        return steps;
      }
    }

    if (row - 1 >= 0 && !visited[row - 1][column] && !isWall(maze[row - 1][column])) {
      visited[row - 1][column] = true;
      positions.push({row - 1, column, steps + 1});
    }

    if (column - 1 >= 0 && !visited[row][column - 1] && !isWall(maze[row][column - 1])) {
      visited[row][column - 1] = true;
      positions.push({row, column - 1, steps + 1});
    }

    if (column + 1 < columns && !visited[row][column + 1] && !isWall(maze[row][column + 1])) {
      visited[row][column + 1] = true;
      positions.push({row, column + 1, steps + 1});
    }

    if (row + 1 < rows && !visited[row + 1][column] && !isWall(maze[row + 1][column])) {
      visited[row + 1][column] = true;
      positions.push({row + 1, column, steps + 1});
    }
  }

  return -1;
}

bool NearestExitFromEntranceInMaze::isWall(const char symbol) const {
  return symbol == '+';
}
