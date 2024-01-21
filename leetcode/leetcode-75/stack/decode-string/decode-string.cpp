#include "decode-string.h"

std::string DecodeString::decodeString(const std::string &s) const {
    std::stringstream result_stream;
    std::stack<int> frequency;
    std::stack<std::string> words;

    std::stringstream substr;
    int i = 0;
    while (i < s.size()) {
        if (s[i] == '[') {
            frequency.push(std::stoi(substr.str()));
            substr.str("");
        } else if (s[i] == ']') {
            words.push(substr.str());
            substr.str("");
        } else {
            substr << s[i];
        }
        i += 1;
    }

    int length;
    while (!words.empty()) {
        length = frequency.top();
        for (int j = 0; j < length; ++j) {
            result_stream.str(words.top() + result_stream.str());
        }
        words.pop();
        frequency.pop();
    }

    return result_stream.str();
}
