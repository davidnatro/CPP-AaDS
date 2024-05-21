#include <iostream>
#include "leetcode-75/trie/search-suggestions-system/search-suggestions-system.hpp"

int main() {
  SearchSuggestionsSystem search_suggestions_system;
  auto result =
      search_suggestions_system.suggestedProducts({ "mobile", "mouse", "moneypot", "monitor",
                                                    "mousepad" }, "mouse");

  for (const std::vector<std::string> &row : result) {
    for (const std::string &column : row) {
      std::cout << column << "\t";
    }
    std::cout << "\n";
  }

  return 0;
}
