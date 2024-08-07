#ifndef INTEGER_TO_ENGLISH_WORDS_HPP
#define INTEGER_TO_ENGLISH_WORDS_HPP

// https://leetcode.com/problems/integer-to-english-words/

#include <map>
#include <string>

class IntegerToEnglishWords {
public:
    IntegerToEnglishWords();

    std::string numberToWords(int num);

private:
    std::map<int, std::string> mappings_;
};

#endif