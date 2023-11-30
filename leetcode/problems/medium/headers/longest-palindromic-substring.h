#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_LONGEST_PALINDROMIC_SUBSTRING_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_LONGEST_PALINDROMIC_SUBSTRING_H_

// https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
#include <iostream>

class Solution {
public:
    std::string dynamicProgramming(const std::string &s) const;

    std::string expandFromCenter(const std::string &s) const;

    std::string manachersAlgorithm(const std::string &s) const;
};

#endif
