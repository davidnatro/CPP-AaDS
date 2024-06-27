#include "ipo.hpp"

int IPO::findMaximizedCapital(int projects,
                              int initial_capital,
                              const std::vector<int> &profits,
                              const std::vector<int> &capital) const {
  int size = profits.size();

  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> capital_min_heap;

  std::priority_queue<int> profit_max_heap;

  for (int i = 0; i < size; ++i) {
    capital_min_heap.push(std::make_pair(capital[i], profits[i]));
  }

  for (int i = 0; i < projects; ++i) {
    while (!capital_min_heap.empty()) {
      std::pair<int, int> project = capital_min_heap.top();
      if (initial_capital >= project.first) {
        profit_max_heap.push(project.second);
        capital_min_heap.pop();
      } else {
        break;
      }
    }

    if (profit_max_heap.empty()) {
      break;
    }

    initial_capital += profit_max_heap.top();
    profit_max_heap.pop();
  }

  return initial_capital;
}
