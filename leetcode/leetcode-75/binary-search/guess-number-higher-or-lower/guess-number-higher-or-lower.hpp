#ifndef LEETCODE_LEETCODE_75_BINARY_SEARCH_GUESS_NUMBER_HIGHER_OR_LOWER_GUESS_NUMBER_HIGHER_OR_LOWER_HPP_
#define LEETCODE_LEETCODE_75_BINARY_SEARCH_GUESS_NUMBER_HIGHER_OR_LOWER_GUESS_NUMBER_HIGHER_OR_LOWER_HPP_

// https://leetcode.com/problems/guess-number-higher-or-lower/

#include <limits>

class GuessNumberHigherOrLower {
 public:
  GuessNumberHigherOrLower(int pick);

  int guessNumber(const int n) const;

 private:
  int guess(const int num) const;

  int pick_;
};

#endif
