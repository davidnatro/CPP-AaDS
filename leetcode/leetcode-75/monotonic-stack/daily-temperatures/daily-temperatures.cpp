#include "daily-temperatures.hpp"

std::vector<int> DailyTemperatures::dailyTemperatures(const std::vector<int> &temperatures) const {
  if (temperatures.empty()) {
    return {};
  }

  std::stack<int> stack;
  std::vector<int> result(temperatures.size(), 0);

  for (int i = 0; i < temperatures.size(); ++i) {
    while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
      int top = stack.top();
      stack.pop();
      if (temperatures[i] > temperatures[top]) {
        result[top] = i - top;
      }
    }
    stack.push(i);
  }

  return result;
}
