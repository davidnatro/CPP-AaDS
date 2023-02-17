#include <iostream>
#include <vector>
#include <chrono>

using std::cin;
using std::cout;

void print(const int data[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
}

void restoreEnd(std::vector<int> &data, int i) {
    int parent = (i - 1) / 2;
    while (i != parent) {
        if (data[parent] < data[i]) {
            std::swap(data[i], data[parent]);
        }

        i = parent;
        parent = (i - 1) / 2;
    }
}

void restoreRoot(std::vector<int> &data, const int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && data[largest] < data[left]) {
        largest = left;
    }

    if (right < size && data[largest] < data[right]) {
        largest = right;
    }

    if (i != largest) {
        std::swap(data[i], data[largest]);
        restoreRoot(data, size, largest);
    }
}

// реализация с лекции
void sort(std::vector<int> &data) {
    for (int i = data.size() - 1; i >= 0; --i) {
        std::swap(data[0], data[i]);
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

    return 0;
}