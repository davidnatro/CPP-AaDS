#include "maximum-number-of-vowels-in-a-substring-of-given-length.h"

int MaximumNumberOfVowelsInASubstringOfGivenLength::maxVowels(const std::string &s, int k) const {
    if (s.empty()) {
        return 0;
    }

    int max;
    int count = 0;

    for (int i = 0; i < k; ++i) {
        if (isVowel(s[i])) {
            count += 1;
        }
    }

    max = count;

    for (int i = 1; i <= s.size() - k; ++i) {
        if (isVowel(s[i - 1])) {
            count -= 1;
        }

        if (isVowel(s[i + k - 1])) {
            count += 1;
        }

        if (count > max) {
            max = count;
        }
    }

    return max;
}

bool MaximumNumberOfVowelsInASubstringOfGivenLength::isVowel(char symbol) const {
    return symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u';
}
