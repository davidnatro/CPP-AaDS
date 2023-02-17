#include <chrono>
#include <iostream>
#include <vector>

int getMax(const std::vector<int> &data) {
    int max = data[0];
    for (int i = 1; i < data.size(); i++)
        if (data[i] > max)
            max = data[i];
    return max;
}

void countSort(std::vector<int> &data, int exp) {
    std::vector<int> output(data.size());
    int count[10] = {0};

    for (const int i : data) {
        count[(i / exp) % 10] += 1;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = data.size() - 1; i >= 0; i--) {
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        count[(data[i] / exp) % 10] -= 1;
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] = output[i];
    }
}

void radixSort(std::vector<int> &data) {
    int m = getMax(data);

    for (int exp = 1; m / exp > 0; exp *= 10) {
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

    return 0;
}
