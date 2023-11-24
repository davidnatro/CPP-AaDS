#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_ATOI_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_ATOI_H_

#include <iostream>
#include <string>

class Atoi {
public:
    int myAtoi(std::string s);

private:
    int max_ = INT32_MAX;
    int min_ = INT32_MIN;
};

#endif
