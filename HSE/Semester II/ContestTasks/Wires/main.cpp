#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

void input(int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }
}

int countRopes(const int data[], const int size, const int length) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        count += data[i] / length;
    }
    return count;
}

int maxLength(const int data[], const int size, const int k) {
    int left = 1;
    int right = data[size - 1];
    int result = -1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (countRopes(data, size, mid) >= k) {
            result = mid;
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

    uint16_t n, k;
    cin >> n >> k;

    int segments[n];

    input(segments, n);

    std::sort(segments, segments + n);

    int max = maxLength(segments, n, k);
    cout << ((max == -1) ? 0 : max);

    return 0;
}
