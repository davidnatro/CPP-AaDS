#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;

// #include <fstream>                        // delete
// std::ifstream f_in("../inputs/input_1");  // delete

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // cin.rdbuf(f_in.rdbuf());  // delete

    std::vector<int> data;

    int operations;
    cin >> operations;
    operations += 1;

    std::string command;
    int credits;

    while (--operations) {
        cin >> command;
        if (command == "+") {
            cin >> credits;
            if (!data.empty()) {
                if (credits < *data.begin()) {
                    data.emplace(data.begin(), credits);
                }
                for (auto it = data.end() - 1; it != data.begin() - 1; --it) {
                    if (credits > *it) {
                        data.emplace(it + 1, credits);
                        break;
                    }
                }
            } else {
                data.emplace_back(credits);
            }
        } else if (command == "-") {
            cin >> credits;

            for (auto it = data.begin(); it != data.end(); ++it) {
                if (*it == credits) {
                    data.erase(it);
                    break;
                }
            }
        } else if (command == "?") {
            cin >> credits;
            cout << data[credits - 1] << "\n";
        }

        if (operations % 10 == 0) {
            cout.flush();
        }
    }

    return 0;
}
