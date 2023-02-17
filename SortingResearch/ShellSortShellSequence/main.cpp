#include <chrono>
#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    const int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            const int temp = arr[i];
            int j = i;
            for (; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main(int argc, char* argv[]) {
    std::vector<int> data;

    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    shellSort(data);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds << "\n";
    int data_size = argc - 2;
    for (int i = 0; i < data_size; ++i) {
        std::cout << data[i] << "\t";
    }

    return 0;
}
