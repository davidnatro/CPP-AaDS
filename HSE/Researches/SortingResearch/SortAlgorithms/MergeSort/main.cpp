#include <iostream>
#include <vector>
#include <chrono>

using std::vector;

void merge(vector<int> &nums, int left, int mid, int right) {
    vector<int> left_arr(mid - left + 1);
    vector<int> right_arr(right - mid);

    for (int i = 0; i < left_arr.size(); i++) {
        left_arr[i] = nums[left + i];
    }
    for (int i = 0; i < right_arr.size(); i++) {
        right_arr[i] = nums[mid + i + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] <= right_arr[j]) {
            nums[k] = left_arr[i];
            i++;
        } else {
            nums[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_arr.size()) {
        nums[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_arr.size()) {
        nums[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main(int argc, char *argv[]) {
    std::vector<int> data;

    for (int i = 2; i < argc; ++i) {
        data.emplace_back(std::stoi(argv[i]));
    }

    auto start = std::chrono::high_resolution_clock::now();

    mergeSort(data, 0, data.size() - 1);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    std::cout << nanoseconds << "\n";
    int data_size = argc - 2;
    for (int i = 0; i < data_size; ++i) {
        std::cout << data[i] << "\t";
    }

    return 0;
}