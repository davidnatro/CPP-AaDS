#include "../headers/longest-palindromic-substring.h"

std::string Solution::dynamicProgramming(const std::string &s) const {
    int range[2];
    bool dp[s.size()][s.size()];

    for (int i = 0; i < s.size(); ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            range[0] = i;
            range[1] = i + 1;
            dp[i][i + 1] = true;
        }
    }

    for (int diff = 2; diff < s.size(); diff++) {
        for (int i = 0; i < s.size() - diff; i++) {
            int j = i + diff;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                range[0] = i;
                range[1] = j;
            }
        }
    }

    return s.substr(range[0], range[1] + 1);
}

std::string Solution::expandFromCenter(const std::string &s) const {
}

std::string Solution::manachersAlgorithm(const std::string &s) const {
}