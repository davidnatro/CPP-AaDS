#ifndef LEETCODE_LEETCODE_75_TRIE_SEARCH_SUGGESTIONS_SYSTEM_SEARCH_SUGGESTIONS_SYSTEM_HPP_
#define LEETCODE_LEETCODE_75_TRIE_SEARCH_SUGGESTIONS_SYSTEM_SEARCH_SUGGESTIONS_SYSTEM_HPP_

// https://leetcode.com/problems/search-suggestions-system/

#include <vector>
#include <string>

class SearchSuggestionsSystem {
 public:
  std::vector<std::vector<std::string>> suggestedProducts(const std::vector<std::string> &products,
                                                          const std::string &search_word) const;
};

#endif
