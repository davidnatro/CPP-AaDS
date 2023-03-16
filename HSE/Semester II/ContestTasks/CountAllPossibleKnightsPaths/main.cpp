#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    n += 2;
    m += 2;

    std::vector<std::vector<uint64_t>> data(n + 1, std::vector<uint64_t>(m + 1, 0));
    data[2][2] = 1;
    int i = 2;
    int j = 2;

    while (i < n - 1 || j < m - 1) {
        int i_2 = i;
        int j_2 = j;
        while (i_2 >= 2 && j_2 < m) {
            data[i_2][j_2] += data[i_2 - 2][j_2 - 1] + data[i_2 - 2][j_2 + 1] +
                              data[i_2 - 1][j_2 - 2] + data[i_2 + 1][j_2 - 2];
            i_2 -= 1;
            j_2 += 1;
        }

        if (i == n - 1) {
            j += 1;
        } else {
            i += 1;
        }
    }

    data[n - 1][m - 1] += data[n - 3][m - 2] + data[n - 3][m] + data[n - 2][m - 3] + data[n][m - 3];

    cout << data[n - 1][m - 1];

    return 0;
}
