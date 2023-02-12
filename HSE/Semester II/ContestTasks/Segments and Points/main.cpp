#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

// https://www.cyberforum.ru/cpp-beginners/thread1163749.html

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int segments_size, points_size;
    cin >> segments_size >> points_size;

    int left_bounds[segments_size];
    int right_bounds[segments_size];

    for (int i = 0; i < segments_size; ++i) {
        cin >> left_bounds[i] >> right_bounds[i];
    }

    std::sort(left_bounds, left_bounds + segments_size);
    std::sort(right_bounds, right_bounds + segments_size);

    int input, count, left, right, mid;
    for (int i = 0; i < points_size; ++i) {
        cin >> input;

        left = 0;
        right = segments_size - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (left_bounds[mid] > input) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        count = right + 1;

        left = 0;
        right = segments_size - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (right_bounds[mid] < input) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        count -= right + 1;
        cout << count << " ";
    }

    return 0;
}
