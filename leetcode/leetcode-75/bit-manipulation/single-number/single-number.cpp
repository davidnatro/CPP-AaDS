#include "single-number.hpp"

int SingleNumber::singleNumber(const std::vector<int> &nums) const {
  int result = 0;
  for (const int num : nums) {
    result ^= num;
  }

  return result;
}
