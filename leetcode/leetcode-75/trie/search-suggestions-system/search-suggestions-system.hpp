#ifndef LEETCODE_LEETCODE_75_TRIE_SEARCH_SUGGESTIONS_SYSTEM_SEARCH_SUGGESTIONS_SYSTEM_HPP_
#define LEETCODE_LEETCODE_75_TRIE_SEARCH_SUGGESTIONS_SYSTEM_SEARCH_SUGGESTIONS_SYSTEM_HPP_

// https://leetcode.com/problems/search-suggestions-system/

#include <queue>
#include <vector>
#include <string>

struct Node {
  char letter;
  bool terminal = false;
  Node *children[26]{ nullptr };
};

class Trie {
 public:
  Trie();

  void insert(const std::string &word);

  std::vector<std::string> findSuggested(std::string &prefix) const;

  ~Trie();

 private:
  void dfs(Node *node, std::string &prefix, std::vector<std::string> &result) const;

  void destroy(Node *node);

  Node *root_ = nullptr;
};

class SearchSuggestionsSystem {
 public:
  SearchSuggestionsSystem();

  std::vector<std::vector<std::string>> suggestedProducts(const std::vector<std::string> &products,
                                                          const std::string &search_word) const;

  ~SearchSuggestionsSystem();

 private:
  Trie *trie_ = nullptr;
};

#endif
