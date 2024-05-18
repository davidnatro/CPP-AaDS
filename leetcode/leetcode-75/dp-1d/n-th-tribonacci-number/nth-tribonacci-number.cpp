#include "nth-tribonacci-number.hpp"

int NthTribonacciNumber::tribonacci(const int n) const {
  if (n == 0) {
    return 0;
  }

  if (n == 1 || n == 2) {
    return 1;
  }

  std::vector<int> data(n + 1);

  data[0] = 0;
  data[1] = 1;
  data[2] = 1;

  int i = 3;
  int j = 0;
  int64_t sum = 2;
  while (i <= n) {
    data[i] = sum;
    sum -= data[j];
    sum += data[i];
    j += 1;
    i += 1;
  }

  return data[n];
}
