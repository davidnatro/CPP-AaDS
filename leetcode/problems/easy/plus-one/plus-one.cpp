#include "plus-one.h"

std::vector<int> PlusOne::plusOne(std::vector<int> &digits) {
    int index = digits.size() - 1;
    while (index >= 0) {
        if (digits[index] == 9) {
            digits[index] = 0;
        } else {
            digits[index] += 1;
            return digits;
        }

        index -= 1;
    }

    digits.emplace_back(0);
    digits[0] = 1;
    return digits;
}