#include "group-anagrams.hpp"

std::vector<std::vector<std::string>> GroupAnagrams::groupAnagrams(const std::vector<std::string> &strs) const {
  std::vector<std::vector<std::string>> result;
  std::unordered_map<std::string, std::vector<std::string>> map;

  for (const std::string str : strs) {
    std::string sorted = std::string(str);
    std::sort(sorted.begin(), sorted.end());
    map[sorted].emplace_back(str);
  }

  for (const std::pair<std::string, std::vector<std::string>> entry : map) {
    result.emplace_back(entry.second);
  }

  return result;
}
