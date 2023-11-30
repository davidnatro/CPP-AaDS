#include <iostream>
#include <chrono>
#include <vector>

using std::cin;
using std::cout;

int elementary_operations = 0;

void bubbleSort(std::vector<int> &data) {
    for (int i = 0; i < data.size() - 1; i++) {
        elementary_operations += 4;  // = < - ++
        for (int j = 0; j < data.size() - i - 1; j++) {
            elementary_operations += 5;  // = < - - ++
            elementary_operations += 3;  // data[] >
            if (data[j] > data[j + 1]) {
                elementary_operations += 3;  // swap data[]
                std::swap(data[j], data[j + 1]);
            }
        }
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

    std::cout << elementary_operations;

    return 0;
}
