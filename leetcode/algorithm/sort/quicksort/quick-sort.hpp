#ifndef LEETCODE_ALGORITHM_SORT_QUICKSORT_QUICK_SORT_HPP_
#define LEETCODE_ALGORITHM_SORT_QUICKSORT_QUICK_SORT_HPP_

#include <vector>

class QuickSort {
 public:
  void sort(std::vector<int> &data) const;

 private:
  void quickSort(std::vector<int> &data, const int left, const int right) const;

  int partition(std::vector<int> &data, const int left, const int right) const;
};

#endif
