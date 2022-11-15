#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

// #include <fstream>

using std::cin;
using std::cout;

/*
 * Идея алгоритма взята отсюда + разборы возможных реализаций (без кода).
 * https://olympiads.ru/moscow/2008/team/problems/medians_razbor.pdf
 */
double findMedian(const std::vector<int>& arr1, const std::vector<int>& arr2, int size) {
    int arr1_index = 0;
    int arr2_index = 0;

    int x = 0;
    int y = 0;

    for (int i = 0; i <= size; ++i) {
        x = y;
        if (arr1[arr1_index] <= arr2[arr2_index]) {
            y = arr1[arr1_index];
            ++arr1_index;
        } else {
            y = arr2[arr2_index];
            ++arr2_index;
        }

        if (arr1_index == size) {
            y = arr2[0];
            break;
        }
        if (arr2_index == size) {
            y = arr1[0];
            break;
        }
    }

    return static_cast<double>(x + y) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int16_t sequences;
    int16_t size;
    // std::ifstream f_in("../input.txt");

    cin >> sequences >> size;

    std::vector<std::vector<int>> data(sequences, std::vector<int>(size));

    for (int i = 0; i < sequences; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> data[i][j];
        }
    }

    for (int i = 0; i < sequences; ++i) {
        for (int j = i + 1; j < sequences; ++j) {

            cout << std::fixed << std::setprecision(5) << findMedian(data[i], data[j], size)
                 << "\n";
        }
    }

    return 0;
}
