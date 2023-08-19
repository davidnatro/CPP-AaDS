#include "../headers/length-of-last-word.h"

int LengthOfLastWord::lengthOfLastWord(const std::string &s) {
    int last_index = s.size() - 1;
    while (s[last_index] == ' ') {
        last_index -= 1;
    }

    int count = 0;
    while (last_index >= 0 && s[last_index] != ' ') {
        count += 1;
        last_index -= 1;
    }

    return count;
}