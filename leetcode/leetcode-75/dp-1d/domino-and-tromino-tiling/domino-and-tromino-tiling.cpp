#include "domino-and-tromino-tiling.hpp"

int DominoAndTrominoTiling::numTilings(const int n) const {
  // board 2 x n
  int modulo = std::pow(10, 9) + 7;
  if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  } else if (n == 3) {
    return 5;
  }

  std::vector<int> dp(n);

  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 5;

  for (int i = 3; i < n; ++i) {
    dp[i] = (((2 * (dp[i - 1] % modulo)) % modulo) + dp[i - 3] % modulo) % modulo;
  }

  return dp[n - 1];
}
