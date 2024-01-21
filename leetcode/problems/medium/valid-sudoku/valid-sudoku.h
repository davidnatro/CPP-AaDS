#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_VALID_SUDOKU_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_VALID_SUDOKU_H_

// https://leetcode.com/problems/valid-sudoku/

#include <vector>

class ValidSudoku {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board);

private:
    bool isUniqueInRow(const std::vector<std::vector<char>>& board, const int row,
                       const char element);

    bool isUniqueInColumn(const std::vector<std::vector<char>>& board, const int column,
                          const char element);

    bool isUniqueCube(const std::vector<std::vector<char>>& board, const int row, const int column,
                      const char element);
};

#endif
