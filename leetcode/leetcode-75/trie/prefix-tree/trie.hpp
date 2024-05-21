#ifndef LEETCODE_LEETCODE_75_TRIE_PREFIX_TREE_TRIE_HPP_
#define LEETCODE_LEETCODE_75_TRIE_PREFIX_TREE_TRIE_HPP_

// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>

struct Node {
  char letter;
  bool terminal = false;
  Node *children[26]{ nullptr };
};

class Trie {
 public:
  Trie();

  void insert(std::string word);

  bool search(std::string word);

  bool startsWith(std::string prefix);

  ~Trie();

 private:
  void destroy(Node *node);

  Node *root_ = nullptr;
};

#endif
