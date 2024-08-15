#ifndef ROMAN_TO_INTEGER_HPP
#define ROMAN_TO_INTEGER_HPP

// https://leetcode.com/problems/roman-to-integer/

#include <map>
#include <string>

class RomanToInteger {
public:
    RomanToInteger();

    int romanToInt(const std::string& s);

private:
    std::map<char, int> romans_;
};

#endif