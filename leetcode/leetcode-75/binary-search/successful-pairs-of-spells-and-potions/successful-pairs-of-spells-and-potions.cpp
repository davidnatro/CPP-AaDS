#include "successful-pairs-of-spells-and-potions.hpp"

std::vector<int> SuccessfulPairsOfSpellsAndPotions::successfulPairs(const std::vector<int> &spells,
                                                                    std::vector<int> &potions,
                                                                    const int64_t success) const {
  std::vector<int> pairs(spells.size());
  std::sort(potions.begin(), potions.end());

  for (int i = 0; i < spells.size(); ++i) {
    // spell * x >= success
    // x >= success / spell
    int64_t find = std::ceil(static_cast<double>(success) / static_cast<double>(spells[i]));
    std::vector<int>::iterator
        it = std::lower_bound(potions.begin(), potions.end(), find);
    if (it == potions.end()) {
      pairs[i] = 0;
      continue;
    }

    int index = it - potions.begin();
    pairs[i] = potions.size() - index;
  }

  return pairs;
}
