#include <iostream>

class Solution {
public:
    int strStr(const std::string &haystack, const std::string &needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }


        int needleIndex = -1;
        int index = 0;
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            if (haystack[i] == needle[index]) {
                index = i;
                needleIndex = i;
                for (const char j : needle) {
                    if (haystack[index++] != j) {
                        needleIndex = -1;
                    }
                }

                index = 0;

                if (needleIndex != -1) {
                    return needleIndex;
                }
            }
        }

        return needleIndex;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string needle, haystack;
    std::cin >> haystack >> needle;

    Solution solution;

    std::cout << solution.strStr(haystack, needle);

    return 0;
}
