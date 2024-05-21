#include "edit-distance.hpp"

int EditDistance::minDistance(const std::string &word1, const std::string &word2) const {
  if (word1.empty() || word2.empty()) {
    return std::max(word1.size(), word2.size());
  }

  std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

  for (int i = 1; i <= word1.size(); ++i) {
    dp[i][0] = i;
  }

  for (int j = 1; j <= word2.size(); ++j) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= word1.size(); ++i) {
    for (int j = 1; j <= word2.size(); ++j) {
      if (word1[i - 1] == word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        int insert_or_delete = std::min(dp[i][j - 1], dp[i - 1][j]) + 1;
        int replace = dp[i - 1][j - 1] + 1;
        dp[i][j] = std::min(insert_or_delete, replace);
      }
    }
  }

  return dp[word1.size()][word2.size()];
}
