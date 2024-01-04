#include "determine-if-two-strings-are-close.h"

bool DetermineIfTwoStringsAreClose::closeStrings(std::string word1, std::string word2) const {
    if (word1.size() != word2.size()) {
        return false;
    }
    if (word1 == word2) {
        return true;
    }

    std::vector<int> first_frequency(26, 0);
    std::vector<bool> first_appearance(26, false);
    std::vector<int> second_frequency(26, 0);
    std::vector<bool> second_appearance(26, false);
    for (int i = 0; i < word1.size(); ++i) {
        int index = word1[i] - 'a';
        first_frequency[index] += 1;
        first_appearance[index] = true;
    }

    for (int i = 0; i < word2.size(); ++i) {
        int index = word2[i] - 'a';
        second_frequency[index] += 1;
        second_appearance[index] = true;
    }

    std::sort(first_frequency.begin(), first_frequency.end());
    std::sort(second_frequency.begin(), second_frequency.end());

    return first_frequency == second_frequency && first_appearance == second_appearance;
}
