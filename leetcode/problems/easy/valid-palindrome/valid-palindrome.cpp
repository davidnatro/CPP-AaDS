#include "valid-palindrome.hpp"

bool ValidPalindrome::isPalindrome(std::string s) const {
  int left = 0;
  int right = s.size() - 1;

  while (left <= right) {
    if (!iswalnum(s[left])) {
      left += 1;
      continue;
    }

    if (!iswalnum(s[right])) {
      right -= 1;
      continue;
    }

    if (tolower(s[left]) != tolower(s[right])) {
      return false;
    }

    left += 1;
    right -= 1;
  }

  return true;
}
