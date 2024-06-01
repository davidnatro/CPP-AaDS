#ifndef LEETCODE_LEETCODE_75_MONOTONIC_STACK_ONLINE_STOCK_SPAN_ONLINE_STOCK_SPAN_HPP_
#define LEETCODE_LEETCODE_75_MONOTONIC_STACK_ONLINE_STOCK_SPAN_ONLINE_STOCK_SPAN_HPP_

// https://leetcode.com/problems/online-stock-span/

#include <stack>

class OnlineStockSpan {
 public:
  OnlineStockSpan();

  int next(const int price);

 private:
  std::stack<std::pair<int, int>> stack_;
};

#endif
