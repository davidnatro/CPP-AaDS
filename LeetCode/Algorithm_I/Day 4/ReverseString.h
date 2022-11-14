#ifndef ALGORITHM_I_REVERSESTRING_H
#define ALGORITHM_I_REVERSESTRING_H

#include <vector>

using std::vector;

class ReverseString {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            std::swap(s[start], s[end]);
            ++start;
            --end;
        }
    }
};

#endif//ALGORITHM_I_REVERSESTRING_H
