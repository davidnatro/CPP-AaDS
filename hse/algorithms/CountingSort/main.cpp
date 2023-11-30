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

void sort(int data[], const int size, const int min, const int max) {
    int count_size = max - min + 1;
    int count[count_size];
    int result[size];

    for (int i = 0; i < count_size; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        count[data[i] - min] += 1;
    }

    for (int i = 1; i < count_size; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        result[count[data[i] - min] - 1] = data[i];
        count[data[i] - min] -= 1;
    }

    for (int i = 0; i < size; ++i) {
        data[i] = result[i];
    }
}

void print(const int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int min = 0;
    int max = 0;

    int size;
    cin >> size;

    int data[size];
    input(data, size, min, max);

    sort(data, size, min, max);

    print(data, size);

    return 0;
}
