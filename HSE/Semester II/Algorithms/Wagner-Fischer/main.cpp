#include <iostream>
#include <vector>

using std::cin;
using std::cout;

// Код с лекции

uint16_t levenshtein(const std::string &first, const std::string &second) {
    std::vector<std::vector<uint16_t>> d(first.size() + 1,
                                         std::vector<uint16_t>(second.size() + 1, 0));

    for (size_t i = 0; i <= first.size(); ++i) {
        d[i][0] = i;
    }

    for (size_t i = 0; i <= second.size(); ++i) {
        d[0][i] = i;
    }

    for (size_t j = 1; j <= second.size(); ++j) {
        for (size_t i = 1; i <= first.size(); ++i) {
            if (first[i - 1] == second[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = std::min(d[i - 1][j], std::min(d[i][j - 1], d[i - 1][j - 1])) + 1;
            }
        }
    }

    return d[first.size()][second.size()];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string first, second;
    cin >> first >> second;

    cout << levenshtein(first, second);

    return 0;
}
