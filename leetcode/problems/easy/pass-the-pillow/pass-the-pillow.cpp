#include "pass-the-pillow.hpp"

int PassThePillow::passThePillow(int n, int time) const {
    int rounds = time / (n - 1);
    int extra = time % (n - 1);

    if (rounds % 2 == 0) {
        return extra + 1;
    }

    return n - extra;
}