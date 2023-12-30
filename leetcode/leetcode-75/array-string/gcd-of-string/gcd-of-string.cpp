#include "gcd-of-strings.h"

std::string GcdOfStrings::gcdOfStrings(const std::string &str1, const std::string &str2) {
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    int gcd_length = std::gcd(str1.size(), str2.size());

    return str1.substr(0, gcd_length);
}
