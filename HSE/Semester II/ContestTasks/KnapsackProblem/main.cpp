#include <iostream>
#include <vector>

using std::cin;
using std::cout;

// С лекции
void print(const std::vector<std::vector<int>> &data, const std::vector<int> &stones,
           std::vector<int> &taken_stones, int i, int j) {
    if (data[i][j] == 0) {
        return;
    }

    if (data[i][j] != data[i - 1][j]) {
        print(data, stones, taken_stones, i - 1, j - stones[i - 1]);
        taken_stones.emplace_back(stones[i - 1]);
    } else {
        print(data, stones, taken_stones, i - 1, j);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int stones_size, max_weight;
    cin >> stones_size >> max_weight;

    std::vector<int> stones(stones_size);
    for (int i = 0; i < stones_size; ++i) {
        cin >> stones[i];
    }

    std::vector<std::vector<int>> data(stones_size + 1, std::vector<int>(max_weight + 1));

    for (size_t i = 0; i < data[0].size(); ++i) {
        data[0][i] = 0;
    }

    for (size_t i = 0; i < data.size(); ++i) {
        data[i][0] = 0;
    }

    // С лекции
    for (int i = 1; i <= stones_size; ++i) {
        for (int j = 1; j <= max_weight; ++j) {
            if (j - stones[i - 1] >= 0) {
                data[i][j] =
                    std::max(stones[i - 1] + data[i - 1][j - stones[i - 1]], data[i - 1][j]);
            } else {
                data[i][j] = data[i - 1][j];
            }
        }
    }

    cout << data[stones_size][max_weight] << "\n";

    std::vector<int> taken_stones;

    print(data, stones, taken_stones, stones_size, max_weight);

    cout << taken_stones.size() << "\n";

    for (const int stone : taken_stones) {
        cout << stone << " ";
    }

    return 0;
}