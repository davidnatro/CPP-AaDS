#include "minimum-flips-to-make-a-or-b-equal-to-c.hpp"

int MinimumFlipsToMakeAOrBEqualToC::minFlips(const int a, const int b, const int c) const {
  int count = 0;
  constexpr int size = 32;

  std::bitset<size> a_bits(a);
  std::bitset<size> b_bits(b);
  std::bitset<size> c_bits(c);

  for (int i = 0; i < size; ++i) {
    if (c_bits[i] == 1) {
      if (a_bits[i] == 0 && b_bits[i] == 0) {
        count += 1;
      }
    } else {
      if (a_bits[i] == 1 && b_bits[i] == 1) {
        count += 2;
      } else if (a_bits[i] == 1 || b_bits[i] == 1) {
        count += 1;
      }
    }
  }

  return count;
}
