#include <iostream>

using std::cin;
using std::cout;

void input(int data[], const int size, int &min, int &max) {
    bool first_element = true;
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
        if (first_element) {
            min = data[i];
            max = data[i];
            first_element = false;
        } else {
            if (data[i] < min) {
                min = data[i];
            }
            if (data[i] > max) {
                max = data[i];
            }
        }
    }
}

void countSort(int data[], const int size, const int rad) {
    int count[10]{0};
    int result[size];

    for (int i = 0; i < size; ++i) {
        count[(data[i] / rad) % 256] += 1;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        result[count[(data[i] / rad) % 256] - 1] = data[i];
        count[(data[i] / rad) % 256] -= 1;
    }

    for (int i = 0; i < size; ++i) {
        data[i] = result[i];
    }
}

void radixSort(int data[], const int size, const int max) {
    for (int i = 1; max / i > 0; i *= 10) {
        countSort(data, size, i);
    }
}

void print(int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    int data[size];
    int min, max;
    input(data, size, min, max);

    radixSort(data, size, max);

    print(data, size);

    return 0;
}
