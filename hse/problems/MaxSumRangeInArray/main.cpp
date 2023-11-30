#include <iostream>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    int data[size];

    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    int max = 0;
    int x, y;
    int result = 0;
    int left = -1;
    for (int i = 0; i < size; ++i) {
        max += data[i];
        if (max > result) {
            result = max;
            x = left + 1;
            y = i;
        }

        if (max <= 0) {
            max = 0;
            left = i;
        }
    }

    cout << x << " " << y;

    return 0;
}
