#ifndef MAGIC_SQUARES_IN_GRID_HPP
#define MAGIC_SQUARES_IN_GRID_HPP

// https://leetcode.com/problems/magic-squares-in-grid/

#include <vector>

class MagicSquaresInGrid {
public:
    int numMagicSquaresInside(const std::vector<std::vector<int>>& grid) const;

private:
    bool isMagicSquare(const std::vector<std::vector<int>>& grid, int row, int col) const;
};

#endif