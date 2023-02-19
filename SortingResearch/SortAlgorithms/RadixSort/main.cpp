#include <chrono>
#include <iostream>
#include <vector>

int elementary_operations = 0;

int getMax(const std::vector<int> &data) {
    int max = data[0];
    elementary_operations += 1;  // = data[]
    for (int i = 1; i < data.size(); i++) {
        elementary_operations += 3;  // = < ++
        elementary_operations += 2;  // > data[]
        if (data[i] > max) {
            max = data[i];
            elementary_operations += 2;  // = data[]
        }
    }
    return max;
}

void countSort(std::vector<int> &data, int exp) {
    std::vector<int> output(data.size());
    elementary_operations += 1;  // объявление output
    int count[10] = {0};
    elementary_operations += 11;  // объявление и зануление элементов

    for (const int i : data) {
        elementary_operations += 1;  // обращение к памяти
        count[(i / exp) % 10] += 1;
        elementary_operations += 4;  // % / += и обращение к памяти
    }

    for (int i = 1; i < 10; i++) {
        elementary_operations += 3;  // = < ++
        count[i] += count[i - 1];
        elementary_operations += 3;  // count[] += -
    }

    for (int i = data.size() - 1; i >= 0; i--) {
        elementary_operations += 4;  // - = >= --
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        elementary_operations += 8;  // data[] / % - count[] output[] = data[]
        count[(data[i] / exp) % 10] -= 1;
        elementary_operations += 5;  // data[] / % count[] -=
    }

    for (int i = 0; i < data.size(); i++) {
        elementary_operations += 3;  // = < ++
        data[i] = output[i];
        elementary_operations += 2;  // обращения к памяти массива
    }
}

void radixSort(std::vector<int> &data) {
    int m = getMax(data);
    elementary_operations += 1;  // =

    for (int exp = 1; m / exp > 0; exp *= 10) {
        elementary_operations += 4;  // = / > *=
        countSort(data, exp);
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    radixSort(data);

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
