#include "valid-palindrome.hpp"

bool ValidPalindrome::isPalindrome(std::string s) const {
  auto remove = std::remove_if(s.begin(), s.end(), [&](const char item) {
    return !iswalnum(item);
  });
  s.erase(remove, s.end());
  for (char &letter : s) {
    letter = tolower(letter);
  }

  int left = 0;
  int right = s.size() - 1;

  while (left <= right) {
    if (s[left] != s[right]) {
      return false;
    }

    left += 1;
    right -= 1;
  }

  return true;
}
