#include <iostream>

using std::cin;
using std::cout;

int rightSideBinarySearch(const int array[], const int size, const int key) {
    int left = 0;
    int right = size - 1;
    int mid;
    int result = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (array[mid] == key) {
            result = mid;
            left = mid + 1;
            continue;
        }

        if (array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int leftSideBinarySearch(const int array[], const int size, const int key) {
    int left = 0;
    int right = size - 1;
    int mid;
    int result = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (array[mid] == key) {
            result = mid;
            right = mid - 1;
            continue;
        }

        if (array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint16_t l_size, r_size;

    cin >> l_size >> r_size;

    int left_array[l_size];
    int right_array[r_size];

    for (int i = 0; i < l_size; ++i) {
        cin >> left_array[i];
    }

    for (int i = 0; i < r_size; ++i) {
        cin >> right_array[i];
    }

    int left_index, right_index;

    for (const int element : right_array) {
        left_index = leftSideBinarySearch(left_array, l_size, element);
        right_index = rightSideBinarySearch(left_array, l_size, element);

        if (left_index == -1 || right_index == -1) {
            cout << 0 << "\n";
            continue;
        }

        cout << left_index + 1 << " " << right_index + 1 << "\n";
    }

    return 0;
}
