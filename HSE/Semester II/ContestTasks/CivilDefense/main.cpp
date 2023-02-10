#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

void restoreEnd(std::pair<int, int> data[], int i) {
    int parent = (i - 1) / 2;
    while (i != parent) {
        if (data[parent].first < data[i].first) {
            std::swap(data[i], data[parent]);
        }

        i = parent;
        parent = (i - 1) / 2;
    }
}

void restoreRoot(std::pair<int, int> data[], const int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && data[largest].first < data[left].first) {
        largest = left;
    }

    if (right < size && data[largest].first < data[right].first) {
        largest = right;
    }

    if (i != largest) {
        std::swap(data[i], data[largest]);
        restoreRoot(data, size, largest);
    }
}

// реализация с лекции
void sort(std::pair<int, int> data[], const int size) {
    for (int i = size - 1; i >= 0; --i) {
        std::swap(data[0], data[i]);
        restoreRoot(data, i, 0);
    }
}

int binarySearch(const std::pair<int, int> data[], const int size, const int key) {
    if (key >= data[size - 1].first) {
        return data[size - 1].second;
    }

    if (key <= data[0].first) {
        return data[0].second;
    }

    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (key == data[mid].first) {
            return data[mid].second;
        }

        if (key < data[mid].first) {
            right = mid - 1;
        } else if (key > data[mid].first) {
            left = mid + 1;
        }
    }

    if (data[left].first - key < key - data[right].first) {
        return data[left].second;
    }

    return data[right].second;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int villages_size;
    cin >> villages_size;

    int villages[villages_size];

    for (int i = 0; i < villages_size; ++i) {
        cin >> villages[i];
    }

    int shelters_size;
    cin >> shelters_size;

    std::pair<int, int> shelters[shelters_size];

    int input;
    for (int i = 0; i < shelters_size; ++i) {
        cin >> input;
        shelters[i] = std::make_pair(input, i + 1);
        restoreEnd(shelters, i);
    }

    sort(shelters, shelters_size);

    for (int i = 0; i < villages_size; ++i) {
        cout << binarySearch(shelters, shelters_size, villages[i]) << " ";
    }

    return 0;
}
