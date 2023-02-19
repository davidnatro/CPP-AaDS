#include <iostream>
#include <vector>
#include <chrono>

int elementary_operations = 0;

void shellSort(std::vector<int>& arr) {
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    elementary_operations += 1;  // =
    const int n = arr.size();
    elementary_operations += 1;  // =
    for (int gap : gaps) {
        elementary_operations += 1;  // обращение к элементам массива
        for (int i = gap; i < n; ++i) {
            elementary_operations += 3;  // = < ++
            const int temp = arr[i];
            elementary_operations += 1;  // =
            int j = i;
            elementary_operations += 1;  // =
            for (; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                elementary_operations += 10;  // = >= > && - -= и обращения к элементам массива
            }
            arr[j] = temp;
            elementary_operations += 2;  // = и обращение к элементам массива
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

    std::cout << elementary_operations;

    return 0;
}
