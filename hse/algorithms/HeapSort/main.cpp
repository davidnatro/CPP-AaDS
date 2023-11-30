#include <iostream>

using std::cin;
using std::cout;

void print(const int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

void restoreEnd(int data[], int i) {
    int parent = (i - 1) / 2;
    while (i != parent) {
        if (data[parent] < data[i]) {
            std::swap(data[i], data[parent]);
        }

        i = parent;
        parent = (i - 1) / 2;
    }
}

void restoreRoot(int data[], const int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && data[largest] < data[left]) {
        largest = left;
    }

    if (right < size && data[largest] < data[right]) {
        largest = right;
    }

    if (i != largest) {
        std::swap(data[i], data[largest]);
        restoreRoot(data, size, largest);
    }
}

// реализация с лекции
void sort(int data[], const int size) {
    for (int i = size - 1; i >= 0; --i) {
        std::swap(data[0], data[i]);
        restoreRoot(data, i, 0);
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
        restoreEnd(data, i);
    }

    sort(data, size);

    print(data, size);

    return 0;
}
