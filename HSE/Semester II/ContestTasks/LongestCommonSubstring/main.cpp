#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;

const uint16_t maxSubstringLength(const std::string &first, const std::string &second) {
    std::vector<std::vector<uint16_t>> suffixes(first.size() + 1,
                                                std::vector<uint16_t>(second.size() + 1, 0));

    for (uint16_t i = 1; i <= first.size(); ++i) {
        for (uint16_t j = 1; j <= second.size(); ++j) {
            if (first[i - 1] == second[j - 1]) {
                suffixes[i][j] = suffixes[i - 1][j - 1] + 1;
                continue;
            }

            suffixes[i][j] = std::max(suffixes[i - 1][j], suffixes[i][j - 1]);
        }
    }

    return suffixes[first.size()][second.size()];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string first, second;
    cin >> first >> second;

    cout << maxSubstringLength(first, second);

    return 0;
}
