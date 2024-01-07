
#include "removing-stars-from-a-string.h"

std::string RemovingStarsFromAString::removeStars(const std::string &s) const {
    std::stack<char> letters;

    int stars = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '*') {
            stars += 1;
            continue;
        }

        if (stars > 0) {
            stars -= 1;
        } else {
            letters.push(s[i]);
        }
    }

    std::stringstream stream;
    size_t letters_size = letters.size();
    for (int i = 0; i < letters_size; ++i) {
        stream << letters.top();
        letters.pop();
    }

    return stream.str();
}
