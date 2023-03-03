#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, cuts;
    cin >> size >> cuts;

    cuts += 2;

    std::vector<int> data(cuts);

    data[0] = 0;
    data[cuts - 1] = size;

    for (int i = 1; i < cuts - 1; ++i) {
        cin >> data[i];
    }

    std::vector<std::vector<int>> matrix(cuts, std::vector<int>(cuts));

    for (int i = cuts - 1; i >= 0; --i) {
        for (int j = i + 1; j < cuts; ++j) {
            for (int k = i + 1; k < j; ++k) {
                matrix[i][j] = std::min(matrix[i][j] == 0 ? INT32_MAX : matrix[i][j],
                                        data[j] - data[i] + matrix[i][k] + matrix[k][j]);
            }
        }
    }

    cout << matrix[0][cuts - 1];

    return 0;
}
