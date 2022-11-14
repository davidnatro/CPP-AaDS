#ifndef ALGORITHM_I_REVERSEWORDSINASTRINGIII_H
#define ALGORITHM_I_REVERSEWORDSINASTRINGIII_H

#include <string>

using std::string;

class ReverseWordsInAStringIII {
public:
    string reverseWords(string s) {
        int start_index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' || i == s.size() - 1) {
                int start = start_index;
                int end = (i > 0) ? (i == s.size() - 1 ? i : i - 1) : 0;
                while (start <= end) {
                    std::swap(s[start], s[end]);
                    ++start;
                    --end;
                }

                start_index = i + 1;
            }
        }

        return s;
    }
};

#endif//ALGORITHM_I_REVERSEWORDSINASTRINGIII_H
