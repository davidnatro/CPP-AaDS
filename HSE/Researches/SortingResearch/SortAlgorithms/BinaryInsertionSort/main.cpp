#include <chrono>
#include <iostream>
#include <vector>

int elementary_operations = 0;

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
    int location, j, selected;

    for (int i = 1; i < data.size(); ++i) {
        elementary_operations += 3;  // = < ++
        j = i - 1;
        elementary_operations += 2;  // = -
        selected = data[i];
        elementary_operations += 2;  // = data[]

        location = binarySearch(data, selected, 0, j);
        elementary_operations += 1;  // =

        elementary_operations += 1;  // >=
        while (j >= location) {
            elementary_operations += 3;  // data[] =
            data[j + 1] = data[j];
            j--;
            elementary_operations += 1;  // --
        }
        data[j + 1] = selected;
        elementary_operations += 2;  // data[] =
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

    std::cout << elementary_operations;

    return 0;
}