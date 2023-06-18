#include <iostream>
#include <chrono>

uint64_t naiveSearch(const std::string &pattern, const std::string &text) {
    uint64_t count = 0;

    for (int i = 0; i < text.size(); ++i) {
        int j = 0;
        for (; j < pattern.size(); ++j) {
            if (pattern[j] != text[i + j]) {
                break;
            }
        }

        if (j == pattern.size()) {
            count += 1;
        }
    }

    return count;
}

int main(int argc, char **argv) {
    std::string pattern = argv[1];
    std::string text = argv[2];

    auto start = std::chrono::high_resolution_clock::now();

    naiveSearch(pattern, text);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds;

    return 0;
}
