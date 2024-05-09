#ifndef LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_SMALLEST_NUMBER_IN_INFINITE_SET_SMALLEST_NUMBER_IN_INFINITE_SET_HPP_
#define LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_SMALLEST_NUMBER_IN_INFINITE_SET_SMALLEST_NUMBER_IN_INFINITE_SET_HPP_

// https://leetcode.com/problems/smallest-number-in-infinite-set/

#include <queue>
#include <unordered_set>

class SmallestNumberInInfiniteSet {
 public:
  SmallestNumberInInfiniteSet();

  int popSmallest();

  void addBack(int num);

 private:
  std::unordered_set<int> popped_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> set_;
};

#endif
