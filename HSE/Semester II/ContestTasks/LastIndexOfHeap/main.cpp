#include <iostream>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    int data[size];

    int parent;
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
        parent = (i - 1) / 2;
        if (data[parent] < data[i]) {
            cout << i - 1;
            return 0;
        }
    }

    cout << size - 1;

    return 0;
}
