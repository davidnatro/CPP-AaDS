#include "permutation-in-string.hpp"

bool PermutationInString::checkInclusion(const std::string &s1, const std::string &s2) const {
  if (s1.size() > s2.size()) {
    return false;
  }

  std::vector<int> first(26, 0);
  std::vector<int> second(26);

  for (const char letter : s1) {
    first[letter - 'a'] += 1;
  }

  for (int i = 0; i <= s2.size() - s1.size(); ++i) {
    for (int j = 0; j < 26; ++j) {
      second[j] = 0;
    }

    for (int j = i; j < s1.size() + i; ++j) {
      second[s2[j] - 'a'] += 1;
    }

    if (this->matches(first, second)) {
      return true;
    }
  }

  return false;
}

bool PermutationInString::matches(const std::vector<int> &first,
                                  const std::vector<int> &second) const {
  for (int i = 0; i < 26; ++i) {
    if (first[i] != second[i]) {
      return false;
    }
  }

  return true;
}
