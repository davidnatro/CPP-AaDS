#include "quick-sort.hpp"

void QuickSort::sort(std::vector<int> &data) const {
  if (data.size() <= 1) {
    return;
  }

  quickSort(data, 0, data.size() - 1);
}

void QuickSort::quickSort(std::vector<int> &data, const int left, const int right) const {
  if (left < right) {
    int pivot = partition(data, left, right);
    quickSort(data, left, pivot - 1);
    quickSort(data, pivot, right);
  }
}

int QuickSort::partition(std::vector<int> &data, const int left, const int right) const {
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
