#include "length-of-last-word.hpp"

int LengthOfLastWord::lengthOfLastWord(const std::string& s) const {
    if (s.empty()) {
        return 0;
    }

    int size = 0;
    int index = s.size() - 1;

    while (s[index] == ' ') {
        index -= 1;;
    }

    while (index >= 0 && s[index] != ' ') {
        size += 1;
        index -= 1;
    }

    return size;
}