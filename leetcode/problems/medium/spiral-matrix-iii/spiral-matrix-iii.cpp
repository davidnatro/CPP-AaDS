#include "spiral-matrix-iii.hpp"

std::vector<std::vector<int>> SpiralMatrixIII::spiralMatrixIII(
    int rows, int cols, int r_start, int c_start) const {

    int size = rows * cols;
    std::vector<std::vector<int>> matrix(size, std::vector<int>(2));
    const std::vector<std::vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int index = 0;
    int step = 1;
    int direction = 0;

    while (size >= -1) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < step; ++j) {
                if (r_start >= 0 && r_start < rows && c_start >= 0 && c_start < cols) {
                    matrix[index][0] = r_start;
                    matrix[index][1] = c_start;
                    index += 1;
                }
                r_start += directions[direction][0];
                c_start += directions[direction][1];
            }
            direction = (direction + 1) % 4;
        }
        step += 1;
        size -= 1;
    }

    return matrix;
}