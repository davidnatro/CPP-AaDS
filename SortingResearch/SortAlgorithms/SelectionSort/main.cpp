#include <iostream>
#include <vector>
#include <chrono>

int elementary_operations = 0;

void selectionSort(std::vector<int> &data) {
    int min_idx;
    for (int i = 0; i < data.size() - 1; i++) {
        elementary_operations += 4;  // = < ++ -
        min_idx = i;
        elementary_operations += 1;  // =

        for (int j = i + 1; j < data.size(); j++) {
            elementary_operations += 3;  // + ++ <
            elementary_operations += 1;  // < и обращения к массиву
            if (data[j] < data[min_idx]) {
                min_idx = j;
                elementary_operations += 1;  // =
            }
        }

        elementary_operations += 1;  // !=
        if (min_idx != i) {
            std::swap(data[min_idx], data[i]);
            elementary_operations += 3;  // swap + обращения
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

    std::cout << elementary_operations;

    return 0;
}
