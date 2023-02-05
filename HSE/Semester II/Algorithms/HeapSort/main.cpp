#include <iostream>

using std::cin;
using std::cout;

void print(const int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

void sort(int data[], const int size) {
    for (int i = size - 1; i >= 0; --i) {

    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    int data[size];

    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    sort(data, size);

    print(data, size);

    return 0;
}
