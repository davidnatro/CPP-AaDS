#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;

// По псевдкоду из лекции

std::vector<int> prefixFunction(const std::string &s) {
    std::vector<int> pi(s.size());
    pi[0] = 0;

    int j = 0;
    for (size_t i = 2; i < s.size(); i++) {
        while (j > 0 && s[j + 1] != s[i]) {
            j = pi[j];
        }
        if (s[i] == s[j + 1]) {
            j += 1;
        }
        pi[i] = j;
    }
    return pi;
}

std::vector<int> kmpSearch(const std::string &text, const std::string &pattern) {
    std::vector<int> result;
    std::vector<int> pi = prefixFunction(pattern);
    std::vector<int> rba(pattern.size() + 1);
    int j = rba[0] = -1;
    for (size_t i = 0; i < pattern.size(); i++) {
        while (j >= 0 && pattern[i] != pattern[j]) {
            j = rba[j];
        }
        j++;
        rba[i + 1] = j;
    }
    j = 0;
    for (size_t i = 0; i < text.size(); i++) {
        while (j >= 0 && text[i] != pattern[j]) {
            j = rba[j];
        }
        j++;
        if (j == static_cast<int>(pattern.size())) {
            result.push_back(i - j + 1);
            j = rba[j];
        }
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string pattern, text;

    cin >> pattern >> text;

    std::vector<int> result = kmpSearch(text, pattern);
    cout << result.size() << "\n";

    for (const int i : result) {
        cout << i << "\n";
    }

    return 0;
}
