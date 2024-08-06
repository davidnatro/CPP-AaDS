#include "minimum-number-of-pushes-to-type-word-ii.hpp"

int MinimumNumberOfPushesToTypeWordII::minimumPushes(std::string word) const {
    std::vector<int> frequency(26, 0);
    for (const char letter : word) {
        frequency[letter - 'a'] += 1;
    }

    std::sort(frequency.rbegin(), frequency.rend());

    int count = 0;
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] == 0) {
            break;
        }

        count += (i / 8 + 1) * frequency[i];
    }

    return count;
}