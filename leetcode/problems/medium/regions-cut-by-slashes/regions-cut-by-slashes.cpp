#include "regions-cut-by-slashes.hpp"

int RegionsCutBySlashes::regionsBySlashes(const std::vector<std::string>& grid) const {
    const int grid_size = grid.size();
    std::vector<std::vector<int>> expanded_grid(grid_size * 3, std::vector<int>(grid_size * 3, 0));

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            const int base_row = i * 3;
            const int base_col = j * 3;
            if (grid[i][j] == '\\') {
                expanded_grid[base_row][base_col] = 1;
                expanded_grid[base_row + 1][base_col + 1] = 1;
                expanded_grid[base_row + 2][base_col + 2] = 1;
            } else if (grid[i][j] == '/') {
                expanded_grid[base_row][base_col + 2] = 1;
                expanded_grid[base_row + 1][base_col + 1] = 1;
                expanded_grid[base_row + 2][base_col] = 1;
            }
        }
    }

    int region_count = 0;
    for (int i = 0; i < grid_size * 3; i++) {
        for (int j = 0; j < grid_size * 3; j++) {
            if (expanded_grid[i][j] == 0) {
                floodFill(expanded_grid, i, j);
                region_count += 1;
            }
        }
    }
    return region_count;
}

void RegionsCutBySlashes::floodFill(std::vector<std::vector<int>>& expanded_grid, int row,
                                    int col) const {
    std::queue<std::pair<int, int>> q;
    expanded_grid[row][col] = 1;
    q.push({row, col});

    while (!q.empty()) {
        auto [currentRow, currentCol] = q.front();
        q.pop();
        for (const auto& direction : directions_) {
            int new_row = direction[0] + currentRow;
            int new_col = direction[1] + currentCol;
            if (isValidCell(expanded_grid, new_row, new_col)) {
                expanded_grid[new_row][new_col] = 1;
                q.push({new_row, new_col});
            }
        }
    }
}

bool RegionsCutBySlashes::isValidCell(const std::vector<std::vector<int>>& expanded_grid, int row,
                                      int col) const {
    const int n = expanded_grid.size();
    return row >= 0 && col >= 0 && row < n && col < n &&
           expanded_grid[row][col] == 0;
}