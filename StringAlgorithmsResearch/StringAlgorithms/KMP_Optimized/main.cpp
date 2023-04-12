#include <iostream>
#include <chrono>
#include <vector>

using std::cin;
using std::cout;

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

int main(int argc, char **argv) {
    std::string pattern = argv[1];
    std::string text = argv[2];

    auto start = std::chrono::high_resolution_clock::now();

    kmpSearch(text, pattern);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds;

    return 0;
}
