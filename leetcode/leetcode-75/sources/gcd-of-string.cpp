#include "../headers/gcd-of-strings.h"

std::string GcdOfStrings::gcdOfStrings(std::string str1, std::string str2) {
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    int gcd_length = std::gcd(str1.size(), str2.size());

    return str1.substr(0, gcd_length);
}
