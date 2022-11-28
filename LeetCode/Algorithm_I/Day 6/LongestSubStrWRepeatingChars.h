//
// Created by David Natroshvili on 16.11.2022.
//

#ifndef ALGORITHM_I_LONGESTSUBSTRWREPEATINGCHARS_H
#define ALGORITHM_I_LONGESTSUBSTRWREPEATINGCHARS_H

#include <string>
using std::string;

class LSSWRC {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int max = -1;

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    count = 0;
                } else {
                    ++count;
                    if (count > max) {
                        max = count;
                    }
                }
            }
        }

        return max;
    }
};

#endif//ALGORITHM_I_LONGESTSUBSTRWREPEATINGCHARS_H
