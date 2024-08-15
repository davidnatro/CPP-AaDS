#include "candy.hpp"

int Candy::candy(const std::vector<int>& ratings) const {
    const int size = ratings.size();
    std::vector<int> candies(ratings.size(), 1);
    for (int i = 1; i < size; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = std::max(candies[i], candies[i - 1] + 1);
        }
    }
    for (int i = size - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }
    }
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += candies[i];
    }
    return sum;
}