#include "counting-bits.hpp"

std::vector<int> CountingBits::countBits(const int n) const {
  std::vector<int> result(n + 1);
  for (int i = 0; i <= n; ++i) {
    result[i] = result[i >> 1] + (i & 1);
  }
  return result;
}
