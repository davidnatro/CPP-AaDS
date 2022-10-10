#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;

uint16_t distance(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    int size = arr1.size();
    uint16_t count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr1[i] != arr2[i]) {
            ++count;
        }
    }
    return count;
}

void print(const std::vector<int>& vector) {
    int size = vector.size();
    for (int i = 0; i < size; ++i) {
        cout << vector[i];
        if (i != size - 1) {
            cout << " ";
        }
    }
}

int main() {
    int16_t size;
    cin >> size;
    uint16_t max = 0;
    std::vector<int> data(size);
    std::set<std::vector<int>> vectors;

    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    std::vector<int> arr(data);
    for (int i = 0; i < size; ++i) {
        int temp = arr[size - 1];
        for (int j = arr.size() - 1; j > 0; --j) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
        int16_t dist = distance(data, arr);
        if (dist > max) {
            max = dist;
        }
    }

    cout << max << "\n";

    if (max == 0) {
        print(data);
        cout << "; 0";
    } else {
        for (int i = 0; i < size; ++i) {
            int temp = arr[size - 1];
            for (int j = arr.size() - 1; j > 0; --j) {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
            int16_t dist = distance(data, arr);
            if (dist == max) {
                if (vectors.find(arr) == vectors.end()) {
                    print(arr);
                    cout << "; " << i + 1 << '\n';
                    vectors.insert(arr);
                }
            }
        }
    }

    //    for (int i = 0; i < size; ++i) {
    //        int temp = data[0];
    //        for (int j = 0; j < size - 1; ++j) {
    //            data[j] = data[j + 1];
    //        }
    //        data[size - 1] = temp;
    //        int16_t dist = distance(data, arr);
    //        if (dist == max) {
    //            for (int j = 0; j < size; ++j) {
    //                cout << data[j];
    //                if (j != size - 1) {
    //                    cout << " ";
    //                }
    //            }
    //            if (i == size - 1) {
    //                cout << "; 0";
    //            } else {
    //                cout << "; " << i + 1;
    //            }
    //            cout << "\n";
    //        }
    //    }

    return 0;
}
