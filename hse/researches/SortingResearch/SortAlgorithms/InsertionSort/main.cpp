#include <chrono>
#include <iostream>
#include <vector>

int elementary_operations = 0;

void insertionSort(std::vector<int> &data) {
    int key, j;
    for (int i = 1; i < data.size(); i++) {
        elementary_operations += 3; // = < ++
        key = data[i];
        elementary_operations += 2; // = data[]
        j = i - 1;
        elementary_operations += 2; // = -

        while (j >= 0 && data[j] > key) {
            elementary_operations += 3; // >= data[] >
            data[j + 1] = data[j];
            elementary_operations += 3; // data[] =
            j = j - 1;
            elementary_operations += 2; // = -
        }
        data[j + 1] = key;
        elementary_operations += 2; // data[] =
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
