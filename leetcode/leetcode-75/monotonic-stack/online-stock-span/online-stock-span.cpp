#include "online-stock-span.hpp"

OnlineStockSpan::OnlineStockSpan() { }

int OnlineStockSpan::next(const int price) {
  int span = 1;
  while (!this->stack_.empty() && this->stack_.top().first <= price) {
    span += this->stack_.top().second;
    stack_.pop();
  }
  this->stack_.push(std::make_pair(price, span));
  return span;
}
