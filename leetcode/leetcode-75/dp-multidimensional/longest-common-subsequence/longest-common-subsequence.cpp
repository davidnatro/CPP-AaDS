#include "longest-common-subsequence.hpp"

int LongestCommonSubsequence::longestCommonSubsequence(const std::string &text1,
                                                       const std::string &text2) const {
  int n = text1.size();
  int m = text2.size();
  std::vector<std::vector<int>> data(n + 1, std::vector<int>(m + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (text1[i - 1] == text2[j - 1]) {
        data[i][j] = data[i - 1][j - 1] + 1;
      } else {
        data[i][j] = std::max(data[i][j - 1], data[i - 1][j]);
      }
    }
  }

  return data[n][m];
}
