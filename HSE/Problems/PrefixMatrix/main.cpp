#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const int64_t sum(const std::vector<std::vector<int64_t>> &data, int x1, int y1, int x2, int y2) {
    x1 -= 1;
    x2 -= 1;
    y1 -= 1;
    y2 -= 1;

    int64_t result = data[x2][y2];

    if (x1 > 0) {
        result -= data[x1 - 1][y2];
    }

    if (y1 > 0) {
        result -= data[x2][y1 - 1];
    }

    if (x1 > 0 && y1 > 0) {
        result += data[x1 - 1][y1 - 1];
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, columns, operations;
    cin >> rows >> columns >> operations;

    std::vector<std::vector<int64_t>> data(rows, std::vector<int64_t>(columns));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i == 0 && j == 0) {
                cin >> data[i][j];
            } else if (i == 0 && j > 0) {
                cin >> data[i][j];
                data[i][j] += data[i][j - 1];
            } else if (i > 0 && j == 0) {
                cin >> data[i][j];
                data[i][j] += data[i - 1][j];
            } else {
                cin >> data[i][j];
                data[i][j] += data[i - 1][j] + data[i][j - 1] - data[i - 1][j - 1];
            }
        }
    }

    int x1, x2, y1, y2;
    for (int i = 0; i < operations; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum(data, x1, y1, x2, y2) << "\n";
    }

    return 0;
}
