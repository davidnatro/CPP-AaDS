#ifndef SPIRAL_MATRIX_III_HPP
#define SPIRAL_MATRIX_III_HPP

// https://leetcode.com/problems/spiral-matrix-iii/

#include <vector>

class SpiralMatrixIII {
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int r_start,
                                                  int c_start) const;
};

#endif