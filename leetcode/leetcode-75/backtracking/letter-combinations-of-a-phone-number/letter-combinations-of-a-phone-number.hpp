#ifndef LEETCODE_LEETCODE_75_BACKTRACKING_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_
#define LEETCODE_LEETCODE_75_BACKTRACKING_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_HPP_

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
#include <unordered_map>

class LetterCombinationsOfAPhoneNumber {
 public:
  std::vector<std::string> letterCombinations(const std::string &digits);

 private:
  std::unordered_map<uint8_t, std::string> keyboard_{
      { 2, "abc" },
      { 3, "def" },
      { 4, "ghi" },
      { 5, "jkl" },
      { 6, "mno" },
      { 7, "pqrs" },
      { 8, "tuv" },
      { 9, "wxyz" }
  };
};

#endif
