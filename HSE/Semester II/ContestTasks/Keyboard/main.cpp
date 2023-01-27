#include <iostream>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int keys;
    cin >> keys;

    int keys_data[keys];

    for (int i = 0; i < keys; ++i) {
        cin >> keys_data[i];
    }

    int all_pushes;
    cin >> all_pushes;

    int key;
    for (int i = 0; i < all_pushes; ++i) {
        cin >> key;
        keys_data[key - 1] -= 1;
    }

    for (const int key_pushes : keys_data) {
        if (key_pushes < 0) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
