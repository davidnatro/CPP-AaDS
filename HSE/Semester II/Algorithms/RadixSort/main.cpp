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

//void radixSort(int data[], const int size, const int max) {
//    for (int i = 1; max / i > 0; i *= 10) {
//        countSort(data, size, i);
//    }
//}

void print(int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

//int main() {
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int size;
//    cin >> size;
//
//    int data[size];
//    int min, max;
//    input(data, size, min, max);
//
//    radixSort(data, size, max);
//
//    print(data, size);
//
//    return 0;
//}


#include <iostream>
#include <vector>

void radixSort(std::vector<int>& arr) {
    const int base = 256;
    std::vector<int> temp(arr.size());
    for (int i = 0; i < 4; i++) {
        std::vector<int> count(base);
        for (int j = 0; j < arr.size(); j++) {
            count[(arr[j] >> (i * 8)) & (base - 1)]++;
        }
        for (int j = 1; j < base; j++) {
            count[j] += count[j - 1];
        }
        for (int j = arr.size() - 1; j >= 0; j--) {
            temp[--count[(arr[j] >> (i * 8)) & (base - 1)]] = arr[j];
        }
        arr = temp;
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }
    return 0;
}
