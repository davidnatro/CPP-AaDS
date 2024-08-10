#include "magic-squares-in-grid.hpp"

int MagicSquaresInGrid::numMagicSquaresInside(const std::vector<std::vector<int>>& grid) const {
    int result = 0;
    const int m = grid.size();
    const int n = grid[0].size();
    for (int row = 0; row + 2 < m; row++) {
        for (int col = 0; col + 2 < n; col++) {
            if (isMagicSquare(grid, row, col)) {
                result += 1;
            }
        }
    }
    return result;
}

bool MagicSquaresInGrid::isMagicSquare(const std::vector<std::vector<int>>& grid, int row,
                                       int col) const {
    const std::string sequence = "2943816729438167";
    const std::string sequence_reversed = "7618349276183492";

    std::string border;
    std::vector<int> border_indices = {0, 1, 2, 5, 8, 7, 6, 3};
    for (const int i : border_indices) {
        const int num = grid[row + i / 3][col + (i % 3)];
        border += std::to_string(num);
    }

    return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
            (sequence.find(border) != std::string::npos ||
             sequence_reversed.find(border) != std::string::npos));
}