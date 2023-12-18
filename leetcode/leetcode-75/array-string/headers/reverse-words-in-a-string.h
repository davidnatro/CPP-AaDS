#ifndef LEETCODE_LEETCODE_75_ARRAY_STRING_HEADERS_REVERSE_WORDS_IN_A_STRING_H_
#define LEETCODE_LEETCODE_75_ARRAY_STRING_HEADERS_REVERSE_WORDS_IN_A_STRING_H_

// https://leetcode.com/problems/reverse-words-in-a-string/

#include <string>
#include <iostream>

class ReverseWordsInAString {
public:
    std::string inPlace(std::string s);

    std::string outOfPlace(std::string s);
};

#endif
