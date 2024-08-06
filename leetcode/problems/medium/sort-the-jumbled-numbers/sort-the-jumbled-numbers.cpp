#include "sort-the-jumbled-numbers.hpp"

std::vector<int> SortTheJumbledNumbers::sortJumbled(const std::vector<int>& mapping,
                                                    std::vector<int>& nums) const {
    std::vector<int> digits;
    std::map<int, int> mapped;

    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        do {
            int digit = num % 10;
            digits.emplace_back(digit);
            num /= 10;
        } while (num > 0);
        int number = 0;
        for (int j = digits.size() - 1; j >= 0; --j) {
            number = number * 10 + mapping[digits[j]];
        }
        mapped[nums[i]] = number;
        digits.clear();
    }

    std::sort(nums.begin(), nums.end(), [&](const int first, const int second) {
        return mapped[first] < mapped[second];
    });

    return nums;
}