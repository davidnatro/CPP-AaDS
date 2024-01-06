#include "equal-row-and-column-pairs.h"

int EqualRowAndColumnPairs::equalPairsBruteForce(const std::vector<std::vector<int>> &grid) const {
    int result = 0;
    std::vector<std::vector<int>> columns(grid.size(), std::vector<int>(grid.size()));

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid.size(); ++j) {
            columns[i][j] = grid[j][i];
        }
    }

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid.size(); ++j) {
            if (grid[i] == columns[j]) {
                result += 1;
            }
        }
    }

    return result;
}
