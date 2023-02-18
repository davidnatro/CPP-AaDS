#include <chrono>
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &data, const int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == data[mid])
            return mid + 1;
        else if (item > data[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

void insertionSort(std::vector<int> &data) {
    int i, location, j, selected;

    for (i = 1; i < data.size(); ++i) {
        j = i - 1;
        selected = data[i];

        location = binarySearch(data, selected, 0, j);

        while (j >= location) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = selected;
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    insertionSort(data);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds << "\n";
    int data_size = argc - 2;
    for (int i = 0; i < data_size; ++i) {
        std::cout << data[i] << "\t";
    }

    return 0;
}