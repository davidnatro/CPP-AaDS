#include "find-the-highest-altitude.h"

int FindTheHighestAltitude::largestAltitude(const std::vector<int> &gain) const {
    int max = 0;
    int prefix = 0;

    for (const int altitude : gain) {
        prefix += altitude;
        if (prefix > max) {
            max = prefix;
        }
    }

    return max;
}
