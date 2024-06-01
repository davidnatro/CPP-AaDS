#include "search-suggestions-system.hpp"

Trie::Trie() {
  root_ = new Node();
}

void Trie::insert(const std::string &word) {
  Node *node = root_;
  for (int i = 0; i < word.size(); ++i) {
    int index = word[i] - 'a';
    if (node->children[index] == nullptr) {
      node->children[index] = new Node();
    }
    node->children[index]->letter = word[i];
    if (i == word.size() - 1) {
      node->children[index]->terminal = true;
    }
    node = node->children[index];
  }
}

std::vector<std::string> Trie::findSuggested(std::string &prefix) const {
  std::vector<std::string> result;
  Node *node = root_;

  for (const char letter : prefix) {
    int index = letter - 'a';
    if (node->children[index] == nullptr) {
      return result;
    }

    node = node->children[index];
  }

  dfs(node, prefix, result);
  return result;
}

Trie::~Trie() {
  destroy(root_);
}

void Trie::dfs(Node *node, std::string &prefix, std::vector<std::string> &result) const {
  if (result.size() == 3) {
    return;
  }

  if (node->terminal) {
    result.emplace_back(prefix);
  }

  for (char letter = 'a'; letter <= 'z'; ++letter) {
    int index = letter - 'a';
    if (node->children[index]) {
      prefix += letter;
      dfs(node->children[index], prefix, result);
      prefix.pop_back();
    }
  }
}

void Trie::destroy(Node *node) {
  if (node == nullptr) {
    return;
  }

  for (Node *child : node->children) {
    destroy(child);
  }

  delete node;
}

SearchSuggestionsSystem::SearchSuggestionsSystem() {
  this->trie_ = new Trie();
}

std::vector<std::vector<std::string>> SearchSuggestionsSystem::suggestedProducts(const std::vector<
    std::string> &products, const std::string &search_word) const {
  if (search_word.empty()) {
    return {};
  }

  std::vector<std::vector<std::string>>
      result(search_word.size(), std::vector<std::string>());

  for (const std::string &product : products) {
    trie_->insert(product);
  }

  std::string search_for;
  for (int i = 0; i < search_word.size(); ++i) {
    search_for += search_word[i];
    result[i] = trie_->findSuggested(search_for);
  }

  return result;
}

SearchSuggestionsSystem::~SearchSuggestionsSystem() {
  delete this->trie_;
  this->trie_ = nullptr;
}
