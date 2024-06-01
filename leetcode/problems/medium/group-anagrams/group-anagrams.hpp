#ifndef LEETCODE_PROBLEMS_MEDIUM_GROUP_ANAGRAMS_GROUP_ANAGRAMS_HPP_
#define LEETCODE_PROBLEMS_MEDIUM_GROUP_ANAGRAMS_GROUP_ANAGRAMS_HPP_

// https://leetcode.com/problems/group-anagrams/

#include <vector>
#include <unordered_map>

class GroupAnagrams {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs) const;
};

#endif
