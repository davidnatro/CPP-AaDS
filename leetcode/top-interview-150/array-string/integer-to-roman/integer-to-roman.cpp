#include "integer-to-roman.hpp"

std::string IntegerToRoman::intToRoman(int num) const {
    const int n[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string s[]{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    std::string result;
    while (num > 0) {
        if (num >= n[i]) {
            result += s[i];
            num -= n[i];
        } else {
            i += 1;
        }
    }
    return result;
}