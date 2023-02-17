#include <iostream>
#include <vector>
#include <chrono>

int partition(std::vector<int> &data, int low, int high) {
    int pivot = data[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);

    return i + 1;
}

void quickSort(std::vector<int> &data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);

        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    quickSort(data, 0, data.size() - 1);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds << "\n";
    int data_size = argc - 2;
    for (int i = 0; i < data_size; ++i) {
        std::cout << data[i] << "\t";
    }

    return 0;
}
