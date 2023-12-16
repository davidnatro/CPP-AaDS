#include "../headers/merge-strings-alternately.h"

std::string MergeStringsAlternately::mergeAlternately(std::string word1, std::string word2) {
    std::string result;

    for (int i = 0; i < word1.size(); ++i) {
        result += word1[i];
        if (i < word2.size()) {
            result += word2[i];
        }
    }

    if (word1.size() < word2.size()) {
        for (int i = word1.size(); i < word2.size(); ++i) {
            result += word2[i];
        }
    }

    return result;
}