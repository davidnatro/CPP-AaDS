#include <iostream>
#include <string>

using std::cin;
using std::cout;

std::string longestPalindrome(const std::string &input, const int size) {
    std::string beg, mid, end;
    int count[256]{0};

    for (int i = 0; i < size; ++i) {
        count[input[i]] += 1;
    }

    char letter = 'A';

    while (letter <= 'Z') {
        if (count[letter] % 2 != 0) {
            mid = letter;
            count[letter] -= 1;
            continue;
        }

        for (int i = 0; i < count[letter] / 2; ++i) {
            beg += letter;
        }

        letter += 1;
    }

    for (int i = beg.size() - 1; i >= 0; --i) {
        end += beg[i];
    }

    return beg + mid + end;
}

#include <fstream>
std::ifstream f_in("../input.txt");

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin.rdbuf(f_in.rdbuf());
    
    int size;
    std::string input;
    cin >> size >> input;

    cout << longestPalindrome(input, size);

    return 0;
}
