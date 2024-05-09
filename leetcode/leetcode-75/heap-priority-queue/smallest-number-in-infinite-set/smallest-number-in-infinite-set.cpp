#include "smallest-number-in-infinite-set.hpp"

SmallestNumberInInfiniteSet::SmallestNumberInInfiniteSet() {
  for (int i = 1; i <= 1000; ++i) {
    set_.push(i);
  }
}

int SmallestNumberInInfiniteSet::popSmallest() {
  int element = set_.top();
  set_.pop();
  popped_.emplace(element);
  return element;
}

void SmallestNumberInInfiniteSet::addBack(int num) {
  if (!popped_.count(num)) {
    return;
  }

  popped_.erase(num);
  set_.push(num);
}
