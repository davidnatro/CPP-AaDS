#include "pow.h"

double MyPow::myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n == 1 || x == 0) {
        return x;
    }

    double pow = 1.0;

    while (n) {
        if (n % 2 != 0) {
            if (n > 0) {
                pow *= x;
            } else {
                pow /= x;
            }
        }

        x *= x;
        n /= 2;
    }

    return pow;
}