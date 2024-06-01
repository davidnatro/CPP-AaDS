#ifndef LEETCODE_PROBLEMS_MEDIUM_PERMUTATION_IN_STRING_PERMUTATION_IN_STRING_HPP_
#define LEETCODE_PROBLEMS_MEDIUM_PERMUTATION_IN_STRING_PERMUTATION_IN_STRING_HPP_

// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <vector>

class PermutationInString {
 public:
  bool checkInclusion(const std::string &s1, const std::string &s2) const;

 private:
  bool matches(const std::vector<int> &first, const std::vector<int> &second) const;
};

#endif
