#include "watter-bottles.hpp"

int WatterBottles::numWaterBottles(int numBottles, int numExchange) const {
    int result = numBottles;

    while (numBottles >= numExchange) {
        const int bottles = numBottles;
        numBottles /= numExchange;
        result += numBottles;
        numBottles += (bottles % numExchange);
    }

    return result;
}