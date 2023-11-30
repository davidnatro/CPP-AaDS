#include <chrono>
#include <iostream>

void computeLPSArray(const std::string &pattern, int m, int *lps);

void kmpSearch(const std::string &pattern, const std::string &text) {
    int lps[pattern.size()];

    computeLPSArray(pattern, pattern.size(), lps);

    int i = 0;
    int j = 0;
    while ((text.size() - i) >= (pattern.size() - j)) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern.size()) {
            j = lps[j - 1];
        }

        else if (i < text.size() && pattern[j] != text[i]) {

            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}

void computeLPSArray(const std::string &pattern, int m, int *lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {

            if (len != 0) {
                len = lps[len - 1];

            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main(int argc, char **argv) {
    std::string pattern = argv[1];
    std::string text = argv[2];

    auto start = std::chrono::high_resolution_clock::now();

    kmpSearch(pattern, text);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds;

    return 0;
}
