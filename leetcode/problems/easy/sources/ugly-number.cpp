#include "../headers/ugly-number.h"

bool UglyNumber::isUgly(int n) {
    if (n <= 0) {
        return false;
    }

    if (n == 1) {
        return true;
    }

    for (const int prime : std::vector<int>{2, 3, 5}) {
        while (n % prime == 0) {
            n /= prime;
        }
    }

    return n == 1;
}