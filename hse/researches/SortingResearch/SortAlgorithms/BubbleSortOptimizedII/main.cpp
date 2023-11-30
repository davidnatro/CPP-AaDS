#include <chrono>
#include <iostream>
#include <vector>

int elementary_operations = 0;

void bubbleSort(std::vector<int> &data) {
    size_t size = data.size();
    elementary_operations += 1;  // =

    bool sorted;

    while (size > 1) {
        elementary_operations += 1;  // >
        sorted = true;
        elementary_operations += 1;  // =
        int new_size = 0;
        elementary_operations += 1;  // =

        for (int i = 1; i <= size - 1; ++i) {
            elementary_operations += 1;  // =
            elementary_operations += 3;  // <=, -, +
            elementary_operations += 3;  // Сравнение и обращения к элементам массива
            if (data[i - 1] > data[i]) {
                std::swap(data[i - 1], data[i]);
                elementary_operations += 3;  // Обращения к элементам и swap
                new_size = i;
                sorted = false;
                elementary_operations += 2;  // =
            }
        }

        elementary_operations += 1;  // Сравнение
        if (sorted) {
            break;
        }
        size = new_size;
        elementary_operations += 1;  // =
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
