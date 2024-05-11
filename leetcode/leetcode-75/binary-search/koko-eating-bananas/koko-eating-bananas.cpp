#include "koko-eating-bananas.hpp"

int KokoEatingBananas::minEatingSpeed(const std::vector<int> &piles, const int h) {
  int min = 1;
  int max = *std::max_element(piles.begin(), piles.end());

  int mid;
  int64_t hours;
  int result = INT32_MAX;
  while (min <= max) {
    hours = 0;
    mid = min + (max - min) / 2;
    for (const int pile : piles) {
      hours += std::ceil(static_cast<double>(pile) / static_cast<double>(mid));
    }

    if (hours > h) {
      min = mid + 1;
      continue;
    }

    max = mid - 1;
    if (mid < result) {
      result = mid;
    }
  }

  return result == INT32_MAX ? -1 : result;
}
