#include <iostream>
#include <vector>

using std::cin;
using std::cout;

std::vector<int> prefixFunction(const std::string &s) {
    std::vector<int> pi(s.size());
    pi[0] = 0;

    int j = 0;
    for (size_t i = 1; i < s.size(); i++) {
        j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j += 1;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string input;
    cin >> input;

    std::vector<int> pi = prefixFunction(input);
    for (const int i : pi) {
        cout << i << " ";
    }

    return 0;
}
