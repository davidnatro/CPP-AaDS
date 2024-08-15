#include "roman-to-integer.hpp"

RomanToInteger::RomanToInteger() {
    romans_['I'] = 1;
    romans_['V'] = 5;
    romans_['X'] = 10;
    romans_['L'] = 50;
    romans_['C'] = 100;
    romans_['D'] = 500;
    romans_['M'] = 1000;
}

int RomanToInteger::romanToInt(const std::string& s) {
    int result = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (i == s.size() - 1) {
            result += romans_[s[i]];
            break;
        }

        if (romans_[s[i]] >= romans_[s[i + 1]]) {
            result += romans_[s[i]];
        } else {
            result -= romans_[s[i]];
        }
    }

    return result;
}