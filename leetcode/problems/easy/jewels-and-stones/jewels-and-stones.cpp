#include "jewels-and-stones.hpp"

int JewelsAndStones::numJewelsInStones(const std::string &jewels, const std::string &stones) const {
  int result = 0;
  int lowercase[26]{ 0 };
  int uppercase[26]{ 0 };

  for (const char jewel : jewels) {
    if (isupper(jewel)) {
      uppercase[jewel - 'A'] += 1;
      continue;
    }

    lowercase[jewel - 'a'] += 1;
  }

  for (const char stone : stones) {
    if (isupper(stone)) {
      if (uppercase[stone - 'A']) {
        result += 1;
      }
      continue;
    }

    if (lowercase[stone - 'a']) {
      result += 1;
    }
  }

  return result;
}
