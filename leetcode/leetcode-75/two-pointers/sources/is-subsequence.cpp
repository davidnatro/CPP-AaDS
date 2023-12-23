#include "../headers/is-subsequence.h"

bool IsSubsequence::isSubsequence(const std::string &s, const std::string &t) const {
    int index = 0;

    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == s[index]) {
            index += 1;
            if (index >= s.size()) {
                return true;
            }
        }
    }

    return index >= s.size();
}