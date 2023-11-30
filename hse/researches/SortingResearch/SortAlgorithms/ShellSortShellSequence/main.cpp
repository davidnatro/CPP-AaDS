#include <chrono>
#include <iostream>
#include <vector>

int elementary_operations = 0;

void shellSort(std::vector<int>& arr) {
    const int n = arr.size();
    elementary_operations += 1;  // присваивание
    for (int gap = n / 2; gap > 0; gap /= 2) {
        elementary_operations += 4;  // Сравнение, деления, присваивание
        for (int i = gap; i < n; ++i) {
            elementary_operations += 3;  // Сравнение, сложение, присваивание
            const int temp = arr[i];
            elementary_operations += 2;  // обращение к элементу массива, присваивание
            int j = i;
            elementary_operations += 1;  // присваивание
            for (; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                elementary_operations +=
                    10;  // обращения к массива, сравнения, вычитание, присваивание
            }
            arr[j] = temp;
            elementary_operations += 2;  // Обращение к массиву, присваивание
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
