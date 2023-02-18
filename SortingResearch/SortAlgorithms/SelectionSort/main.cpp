#include <iostream>
#include <vector>
#include <chrono>

void selectionSort(std::vector<int> &data) {
    int min_idx;
    for (int i = 0; i < data.size() - 1; i++) {
        min_idx = i;

        for (int j = i + 1; j < data.size(); j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            std::swap(data[min_idx], data[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    selectionSort(data);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds << "\n";
    int data_size = argc - 2;
    for (int i = 0; i < data_size; ++i) {
        std::cout << data[i] << "\t";
    }

    return 0;
}
