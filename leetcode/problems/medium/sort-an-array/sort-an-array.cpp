#include "sort-an-array.hpp"

std::vector<int> SortAnArray::sortArray(std::vector<int>& nums) const {
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
    for (const int num : nums) {
        queue.push(num);
    }

    int index = 0;
    while (!queue.empty()) {
        nums[index] = queue.top();
        queue.pop();
        index += 1;
    }

    return nums;
}