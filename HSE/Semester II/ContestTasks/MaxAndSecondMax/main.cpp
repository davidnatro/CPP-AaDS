#include <iostream>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint16_t max = 0;
    uint16_t second_max = 0;
    uint16_t input;

    cin >> input;

    while (input != 0) {
        if (input > max) {
            second_max = max;
            max = input;
        } else if (input > second_max) {
            second_max = input;
        }
        cin >> input;
    }

    cout << max << "\n" << second_max;

    return 0;
}
