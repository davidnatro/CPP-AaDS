#include "consecutive-characters.hpp"

int ConsecutiveCharacters::maxPower(const std::string &s) const {
  int max = 1;
  int result = 1;

  for (int i = 0; i < s.size() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      result += 1;
      continue;
    }

    if (result > max) {
      max = result;
    }
    result = 1;
  }

  return (result > max) ? result : max;
}
