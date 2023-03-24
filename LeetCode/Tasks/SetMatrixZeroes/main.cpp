#include <iostream>
#include <vector>

void coutMatrix(const std::vector<std::vector<int>> &matrix);

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        std::vector<std::pair<int, int>> coords;

        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    coords.emplace_back(std::make_pair(i, j));
                }
            }
        }

        for (const std::pair<int, int> pair : coords) {
            for (int k = 0; k < matrix[pair.first].size(); ++k) {
                matrix[pair.first][k] = 0;
            }

            for (int k = 0; k < matrix.size(); ++k) {
                matrix[k][pair.second] = 0;
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix(3, std::vector<int>(3, 1));
    matrix[1][1] = 0;

    Solution solution;
    solution.setZeroes(matrix);

    coutMatrix(matrix);

    return 0;
}

void coutMatrix(const std::vector<std::vector<int>> &matrix) {
    std::cout << "==="
              << "\n";
    for (const std::vector<int> &row : matrix) {
        for (const int element : row) {
            std::cout << element << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "==="
              << "\n";
}