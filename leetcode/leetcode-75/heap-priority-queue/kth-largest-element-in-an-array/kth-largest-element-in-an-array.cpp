#include "kth-largest-element-in-an-array.hpp"

int KthLargestElementInAnArray::heapSelect(const std::vector<int> &nums, const int k) const {
  std::priority_queue<int> heap;

  for (const int num : nums) {
    heap.push(num);
  }

  for (int i = 0; i < k - 1; ++i) {
    heap.pop();
  }

  return heap.top();
}

int KthLargestElementInAnArray::quickSelect(std::vector<int> &nums, const int k) const {
  return quickSelect(nums, 0, nums.size() - 1, k);
}

int KthLargestElementInAnArray::quickSelect(std::vector<int> &data,
                                            const int left,
                                            const int right,
                                            const int k) const {
  if (left == right) {
    return data[left];
  }

  int pivot = partition(data, left, right);

  int index = data.size() - k;
  if (index == pivot) {
    return data[index];
  } else if (index < pivot) {
    return quickSelect(data, left, pivot - 1, k);
  } else {
    return quickSelect(data, pivot + 1, right, k);
  }
}

int KthLargestElementInAnArray::partition(std::vector<int> &data,
                                          const int left,
                                          const int right) const {
  int mid = left + (right - left) / 2;
  std::swap(data[mid], data[right]);

  int pivot = data[right];
  int i = left;

  for (int j = left; j < right; j++) {
    if (data[j] < pivot) {
      std::swap(data[i], data[j]);
      i += 1;
    }
  }

  std::swap(data[i], data[right]);
  return i;
}
