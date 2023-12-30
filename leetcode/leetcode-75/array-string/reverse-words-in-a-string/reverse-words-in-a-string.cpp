#include "reverse-words-in-a-string.h"

std::string ReverseWordsInAString::inPlace(std::string s) {
    int start = 0;
    int end = s.size() - 1;

    while (s[start] == ' ' && start <= end) {
        start += 1;
    }

    while (s[end] == ' ' && start <= end) {
        end -= 1;
    }

    int i = 0;
    int j = start;
    while (j <= end) {
        if (j < end && s[j] == ' ' && s[j + 1] == ' ') {
            j += 1;
            continue;
        }
        s[i] = s[j];
        i += 1;
        j += 1;
    }

    s.resize(i);

    std::reverse(s.begin(), s.end());

    i = 0;
    j = 0;

    while (j < s.size()) {

        if (s[j] == ' ') {
            std::reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        j += 1;
    }

    std::reverse(s.begin() + i, s.begin() + j);

    return s;
}

std::string ReverseWordsInAString::outOfPlace(std::string s) {
    std::string result;

    int start = 0;
    int end = s.size() - 1;

    while (s[start] == ' ' && start <= end) {
        start += 1;
    }

    while (s[end] == ' ' && start <= end) {
        end -= 1;
    }

    int i = start;
    int j = end;
    int string_size = 0;
    while (i <= j) {
        string_size += 1;
        if (s[j] != ' ' && (j == 0 || s[j - 1] == ' ')) {
            result += s.substr(j, string_size);
            if (j > i) {
                result += ' ';
            }
            string_size = 0;
        }

        if (s[j] == ' ') {
            string_size = 0;
        }

        j -= 1;
    }

    return result;
}
