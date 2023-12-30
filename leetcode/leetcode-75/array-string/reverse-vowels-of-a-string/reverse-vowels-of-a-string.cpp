#include "reverse-vowels-of-a-string.h"

ReverseVowelsOfAString::ReverseVowelsOfAString() {
    vowels_.insert('a');
    vowels_.insert('A');
    vowels_.insert('e');
    vowels_.insert('E');
    vowels_.insert('i');
    vowels_.insert('I');
    vowels_.insert('o');
    vowels_.insert('O');
    vowels_.insert('u');
    vowels_.insert('U');

    // use unordered_set or method is_vowel(char);
}

std::string ReverseVowelsOfAString::reverseVowels(std::string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left <= right) {
        if (vowels_.count(s[left])) {
            while (left <= right && !vowels_.count(s[right])) {
                right -= 1;
            }
            std::swap(s[left], s[right]);
            right -= 1;
        }

        left += 1;
    }

    return s;
}

bool ReverseVowelsOfAString::is_vowel(char letter) {
    return letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' ||
           letter == 'I' || letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U';
}