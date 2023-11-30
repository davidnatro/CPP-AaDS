#include <chrono>
#include <iostream>
#include <vector>

int elementary_operations = 0;

void countingSort(std::vector<int> &data, const int min, const int max) {
    const int count_size = max - min + 1;
    elementary_operations += 3;  // = - =
    std::vector<int> count(count_size);
    std::vector<int> result(data.size());
    elementary_operations += 2;  // Объявления массивов

    for (int i = 0; i < count_size; ++i) {
        elementary_operations += 3;  // = < ++
        count[i] = 0;
        elementary_operations += 2;  // count[] =
    }

    for (const int i : data) {
        elementary_operations += 1;  // обращение
        count[i - min] += 1;
        elementary_operations += 3;  // count[] - +=
    }

    for (int i = 1; i < count_size; ++i) {
        elementary_operations += 3;  // = < ++
        count[i] += count[i - 1];
        elementary_operations += 3;  // count[] +=
    }

    for (int i = data.size() - 1; i >= 0; --i) {
        elementary_operations += 4;  // = - >= --
        result[count[data[i] - min] - 1] = data[i];
        elementary_operations += 7;  // data[] - count[] - result[] = data[]
        count[data[i] - min] -= 1;
        elementary_operations += 4;  // data[] - count[] -=
    }

    for (int i = 0; i < data.size(); ++i) {
        elementary_operations += 3;  // = < ++
        data[i] = result[i];
        elementary_operations += 3;  // data[] = result[]
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    int min = INT32_MAX;
    int max = INT32_MIN;
    int input;

    for (int i = 2; i < argc; ++i) {
        input = std::stoi(argv[i]);
        data.emplace_back(input);

        if (input < min) {
            min = input;
        }

        if (input > max) {
            max = input;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    countingSort(data, min, max);

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
