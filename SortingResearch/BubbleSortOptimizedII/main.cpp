#include <chrono>
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &data) {
    size_t size = data.size();
    bool sorted;

    while (size > 1) {
        sorted = true;
        int new_size = 0;

        for (int i = 1; i <= size - 1; ++i) {
            if (data[i - 1] > data[i]) {
                std::swap(data[i - 1], data[i]);
                new_size = i;
                sorted = false;
            }
        }
        if (sorted) {
            break;
        }
        size = new_size;
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(data);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds << "\n";
    int data_size = argc - 2;
    for (int i = 0; i < data_size; ++i) {
        std::cout << data[i] << "\t";
    }

    return 0;
}
