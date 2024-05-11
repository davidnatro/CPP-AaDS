#include "guess-number-higher-or-lower.hpp"

GuessNumberHigherOrLower::GuessNumberHigherOrLower(int pick) : pick_(pick) { }

int GuessNumberHigherOrLower::guessNumber(const int n) const {
  int left = 1;
  int right = n;
  int mid = left + (right - left) / 2;

  while (left < right) {
    switch (guess(mid)) {
      case 0: return mid;
      case 1: {
        left = mid + 1;
        break;
      }
      case -1: {
        right = mid - 1;
        break;
      }
    }
    mid = left + (right - left) / 2;
  }

  return mid;
}

int GuessNumberHigherOrLower::guess(const int num) const {
  if (num == pick_) {
    return 0;
  }

  if (num < pick_) {
    return 1;
  }

  return -1;
}
