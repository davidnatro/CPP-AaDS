#include <iostream>
#include <list>

using std::list;

list<int> merge(const list<int> &first, const list<int> &second) {
    list<int> result;

    list<int>::const_iterator i = first.begin();
    list<int>::const_iterator j = second.begin();

    while (i != first.end() && j != second.end()) {
        if (*i <= *j) {
            result.push_back(*i++);
        } else {
            result.push_back(*j++);
        }
    }

    while (i != first.end()) {
        result.push_back(*i++);
    }

    while (j != second.end()) {
        result.push_back(*j++);
    }

    return result;
}

#include <iostream>

int main() {
    int input;

    list<int> first;
    list<int> second;

    for (int i = 0; i < 3; ++i) {
        std::cin >> input;
        first.push_back(input);
    }

    for (auto it = first.begin(); it != first.end(); ++it) {
        std::cout << *it << "\t";
    }
    std::cout << "\n";

    for (int i = 0; i < 6; ++i) {
        std::cin >> input;
        second.push_back(input);
    }

    for (auto it = second.begin(); it != second.end(); ++it) {
        std::cout << *it << "\t";
    }
    std::cout << "\n";

    list<int> merged = merge(first, second);
    for (auto it = merged.begin(); it != merged.end(); ++it) {
        std::cout << *it << "\t";
    }

    return 0;
}