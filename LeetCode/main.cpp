#include <iostream>

#include "problems/medium/headers/longest-palindromic-substring.h"

int main() {
    Solution solution;

    std::string input = "babad";

    std::cout << solution.longestPalindrome(input);

    return 0;
}
