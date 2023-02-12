#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int16_t rows, columns;
    cin >> rows >> columns;

    std::vector<std::vector<int16_t>> data(rows, std::vector<int16_t>(columns, 0));

    std::vector<std::vector<int16_t>> sums(rows, std::vector<int16_t>(columns, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> data[i][j];
        }
    }

    for (int i = 0; i < columns; ++i) {
        sums[0][i] = data[0][i];
    }

    for (int i = 0; i < rows; ++i) {
        sums[i][0] = data[i][0];
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < columns; ++j) {
            sums[i][j] = 0;

            if (data[i][j] == 1) {
                sums[i][j] =
                    1 + std::min(sums[i][j - 1], std::min(sums[i - 1][j], sums[i - 1][j - 1]));
            }
        }
    }

    int16_t max = sums[0][0];
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (sums[i][j] > max) {
                max = sums[i][j];
            }
        }
    }

    cout << max;

    return 0;
}
