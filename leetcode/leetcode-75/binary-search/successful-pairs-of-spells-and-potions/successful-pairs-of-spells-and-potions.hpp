#ifndef LEETCODE_LEETCODE_75_BINARY_SEARCH_SUCCESSFUL_PAIRS_OF_SPELLS_AND_POTIONS_SUCCESSFUL_PAIRS_OF_SPELLS_AND_POTIONS_HPP_
#define LEETCODE_LEETCODE_75_BINARY_SEARCH_SUCCESSFUL_PAIRS_OF_SPELLS_AND_POTIONS_SUCCESSFUL_PAIRS_OF_SPELLS_AND_POTIONS_HPP_

// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <vector>

class SuccessfulPairsOfSpellsAndPotions {
 public:
  std::vector<int> successfulPairs(const std::vector<int> &spells,
                                   std::vector<int> &potions,
                                   const int64_t success) const;
};

#endif
