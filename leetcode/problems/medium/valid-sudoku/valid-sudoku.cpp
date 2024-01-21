#include "valid-sudoku.h"

bool ValidSudoku::isValidSudoku(std::vector<std::vector<char>> &board) {
    for (int row = 0; row < board.size(); ++row) {
        for (int column = 0; column < board[row].size(); ++column) {
            if (!isUniqueInRow(board, row, board[row][column])) {
                return false;
            }

            if (!isUniqueInColumn(board, column, board[row][column])) {
                return false;
            }

            if (!isUniqueCube(board, row - row % 3, column - column % 3, board[row][column])) {
                return false;
            }
        }
    }

    return true;
}

bool ValidSudoku::isUniqueInRow(const std::vector<std::vector<char>> &board, const int row,
                                const char element) {
    int count = 0;

    for (int i = 0; i < 9; ++i) {
        char cell = board[row][i];
        if (cell != '.' && cell == element) {
            count += 1;
        }
    }

    return count <= 1;
}

bool ValidSudoku::isUniqueInColumn(const std::vector<std::vector<char>> &board, const int column,
                                   const char element) {
    int count = 0;

    for (int i = 0; i < 9; ++i) {
        char cell = board[i][column];
        if (cell != '.' && cell == element) {
            count += 1;
        }
    }

    return count <= 1;
}

bool ValidSudoku::isUniqueCube(const std::vector<std::vector<char>> &board, const int row,
                               const int column, const char element) {
    int count = 0;
    for (int i = row; i < row + 3; ++i) {
        for (int j = column; j < column + 3; ++j) {
            char cell = board[i][j];
            if (cell != '.' && cell == element) {
                count += 1;
            }
        }
    }

    return count <= 1;
}