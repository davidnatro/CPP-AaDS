#include <iostream>
#include <vector>

using std::cin;
using std::cout;

// Псевдокод с лекции +  https://ru.wikipedia.org/wiki/Расстояние_Дамерау_—_Левенштейна

uint16_t levenshtein(const std::string &first, const std::string &second) {
    std::vector<std::vector<uint16_t>> d(first.size() + 1,
                                         std::vector<uint16_t>(second.size() + 1));

    for (size_t i = 0; i < first.size(); ++i) {
        d[i][0] = i;
    }

    for (size_t i = 0; i < second.size(); ++i) {
        d[0][i] = i;
    }

    uint16_t cost;
    for (size_t i = 1; i <= first.size(); ++i) {
        for (size_t j = 1; j <= second.size(); ++j) {
            cost = first[i - 1] == second[j - 1] ? 0 : 1;
            d[i][j] = std::min(std::min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);

            if (i > 1 && j > 1 && first[i - 1] == second[j - 2] && first[i - 2] == second[j - 1]) {
                d[i][j] = std::min(d[i][j], static_cast<uint16_t>(d[i - 2][j - 2] + cost));
            }
        }
    }

    return d[first.size()][second.size()];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int strings_size;
    cin >> strings_size;

    std::string first, second;
    for (int i = 0; i < strings_size; ++i) {
        cin >> first >> second;
        cout << levenshtein(first, second) << " ";
    }

    return 0;
}
