#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;

std::list<int>::iterator findPosition(std::list<int>::iterator begin, std::list<int>::iterator end,
                                      int32_t credits) {
    if (*begin >= *end) {
        return begin;
    }

    //std::advance(end, -1);

    std::list<int>::iterator middle = begin;
    uint64_t distance = std::distance(begin, end) / 2;
    std::advance(middle, distance);

    std::list<int>::iterator result;

    if (credits == *middle) {
        return middle;
    }

    if (credits > *middle) {
        //std::advance(middle, 1);
        result = findPosition(middle, end, credits);
    } else if (credits < *middle) {
        //std::advance(middle, -1);
        result = findPosition(begin, middle, credits);
    }

    return result;
}

#include <fstream>                        // delete
std::ifstream f_in("../inputs/input_1");  // delete

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin.rdbuf(f_in.rdbuf());  // delete

    std::list<int> data;

    int operations;
    cin >> operations;
    operations += 1;

    std::string command;
    int credits;

    while (--operations) {
        cin >> command;

        if (command == "+") {
            cin >> credits;
            std::list<int>::iterator position = findPosition(data.begin(), data.end(), credits);
            data.insert(position, credits);
        } else if (command == "-") {
            cin >> credits;
            data.remove(credits);
        } else if (command == "?") {
            cin >> credits;
            std::list<int>::iterator begin = data.begin();
            std::advance(begin, credits - 1);
            cout << *begin << "\n";
        }

        if (operations % 10 == 0) {
            cout.flush();
        }
    }

    return 0;
}
