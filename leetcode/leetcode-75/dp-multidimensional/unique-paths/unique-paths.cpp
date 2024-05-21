#include "unique-paths.hpp"

int UniquePaths::uniquePaths(const int m, const int n) const {
  if (m == 1 || n == 1) {
    return 1;
  }

  std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));

  grid[0][0] = 0;
  grid[0][1] = 1;
  grid[1][0] = 1;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int left = (j - 1 < 0) ? 0 : grid[i][j - 1];
      int right = (i - 1 < 0) ? 0 : grid[i - 1][j];
      grid[i][j] += left + right;
    }
  }

  return grid[m - 1][n - 1];
}
