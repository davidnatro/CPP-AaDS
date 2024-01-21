#include "binary-sum.h"

std::string BinarySum::addBinary(const std::string &a, const std::string &b) {
    std::string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry == 1) {
        if (i >= 0) {
            carry += a[i] - '0';
            i -= 1;
        }
        if (j >= 0) {
            carry += b[j] - '0';
            j -= 1;
        }

        result += carry % 2 + '0';
        carry /= 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
}