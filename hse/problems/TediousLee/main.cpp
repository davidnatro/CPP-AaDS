#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    constexpr int kMod = 1e9 + 7;

    int trees_size;
    cin >> trees_size;

    std::vector<int> trees(trees_size);
    int max_tree = 0;
    for (int i = 0; i < trees_size; ++i) {
        cin >> trees[i];
        if (trees[i] > max_tree) {
            max_tree = trees[i];
        }
    }

    std::vector<int> data(max_tree);

    data[0] = data[1] = 0;
    data[2] = data[3] = 4;
    for (int i = 4; i < max_tree; ++i) {
        uint64_t level = data[i - 1];
        level += 2 * data[i - 2] + (i % 3 == 2) * 4;
        level %= kMod;
        data[i] = level;
    }

    for (const int tree : trees) {
        cout << data[tree - 1] << "\n";
    }

    return 0;
}
