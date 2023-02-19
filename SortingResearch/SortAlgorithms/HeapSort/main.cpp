#include <iostream>
#include <vector>
#include <chrono>

using std::cin;
using std::cout;

int elementary_operations = 0;

void restoreEnd(std::vector<int> &data, int i) {
    int parent = (i - 1) / 2;
    elementary_operations += 3;  // = - /
    while (i != parent) {
        elementary_operations += 1;  // !=
        elementary_operations += 3;  // data[] <
        if (data[parent] < data[i]) {
            elementary_operations += 3;  // swap data[]
            std::swap(data[i], data[parent]);
        }

        elementary_operations += 1;  // =
        i = parent;
        elementary_operations += 3;  // = - /
        parent = (i - 1) / 2;
    }
}

void restoreRoot(std::vector<int> &data, const int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    elementary_operations += 7;  // = * +

    if (left < size && data[largest] < data[left]) {
        elementary_operations += 4;  // < data[] <
        largest = left;
        elementary_operations += 1; // =
    }

    if (right < size && data[largest] < data[right]) {
        elementary_operations += 4; // < data[] <
        largest = right;
        elementary_operations += 1; // =
    }

    if (i != largest) {
        elementary_operations += 1; // !=
        std::swap(data[i], data[largest]);
        elementary_operations += 3; // data[] swap
        restoreRoot(data, size, largest);
    }
}

// реализация с лекции
void sort(std::vector<int> &data) {
    for (int i = data.size() - 1; i >= 0; --i) {
        elementary_operations += 4;  // = - >= --
        std::swap(data[0], data[i]);
        elementary_operations += 3;  // data[] swap
        restoreRoot(data, i, 0);
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    int restore_index = 0;
    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
        restoreEnd(data, restore_index);
        restore_index += 1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    sort(data);

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