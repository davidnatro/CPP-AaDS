#ifndef REGIONS_CUT_BY_SLASHES_HPP
#define REGIONS_CUT_BY_SLASHES_HPP

// https://leetcode.com/problems/regions-cut-by-slashes/

#include <queue>
#include <string>
#include <vector>

class RegionsCutBySlashes {
public:
    int regionsBySlashes(const std::vector<std::string>& grid) const;

private:
    const std::vector<std::vector<int>> directions_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void floodFill(std::vector<std::vector<int>>& expanded_grid, int row, int col) const;

    bool isValidCell(const std::vector<std::vector<int>>& expanded_grid, int row, int col) const;
};

#endif