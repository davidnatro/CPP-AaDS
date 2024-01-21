#include "atoi.h"

int Atoi::myAtoi(std::string s) {
    int sign = 1;
    int result = 0;

    int i = 0;
    while (s[i] == ' ') {
        i += 1;
    }

    if (s[i] == '-') {
        sign = -1;
        i += 1;
    } else if (s[i] == '+') {
        i += 1;
    }

    while (i < s.size()) {
        if (!isdigit(s[i])) {
            break;
        }
        if (result > max_ / 10 || (result == max_ / 10 && s[i] - '0' > 7)) {
            if (sign == 1) {
                return max_;
            } else {
                return min_;
            }
        }
        result = result * 10 + (s[i] - '0');
        i += 1;
    }

    return result * sign;
}