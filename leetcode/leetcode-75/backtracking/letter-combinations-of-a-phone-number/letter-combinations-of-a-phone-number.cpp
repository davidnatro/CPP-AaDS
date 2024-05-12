#include "letter-combinations-of-a-phone-number.hpp"

std::vector<std::string> LetterCombinationsOfAPhoneNumber::letterCombinations(const std::string &digits) {
  std::vector<std::string> result;
  if (digits.empty()) {
    return result;
  }

  result.emplace_back("");
  for (const char digit : digits) {
    std::vector<std::string> combinations;
    for (const std::string &combination : result) {
      for (const char letter : keyboard_[digit - '0']) {
        combinations.emplace_back(combination + letter);
      }
    }
    result = combinations;
  }

  return result;
}
