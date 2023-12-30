#include "kids-with-the-greatest-number-of-candies.h"

std::vector<bool> KidsWithTheGreatestNumberOfCandies::kidsWithCandies(
    const std::vector<int> &candies, int extra_candies) {
    std::vector<bool> result(candies.size());

    int max = INT32_MIN;

    for (const int candy : candies) {
        if (candy > max) {
            max = candy;
        }
    }

    for (int i = 0; i < candies.size(); ++i) {
        if (candies[i] + extra_candies >= max) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }

    return result;
}