#include <vector>

class Solution {
    void transpose(std::vector<std::vector<int>> &matrix) {
        std::vector<std::vector<int>> matr(matrix[0].size(), std::vector<int>(matrix.size()));

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                matr[i][j] = matrix[j][i];
            }
        }
        matrix = matr;
    }

public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        transpose(matrix);
        for (int i = 0; i < matrix.size(); ++i) {
            int start = 0;
            int end = matrix.size() - 1;
            while (start < end) {
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                ++start;
                --end;
            }
        }
    }
};

#include <iostream>

int main() {
    Solution solution;

    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));
    int index = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = index++;
        }
    }

    solution.rotate(matrix);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
