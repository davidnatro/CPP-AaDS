#ifndef LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP_
#define LEETCODE_LEETCODE_75_HEAP_PRIORITY_QUEUE_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP_

// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <queue>
#include <vector>

class KthLargestElementInAnArray {
 public:
  int heapSelect(const std::vector<int> &nums, const int k) const;

  int quickSelect( std::vector<int> &nums, const int k) const;

 private:
  int quickSelect(std::vector<int> &data, const int left, const int right, const int k) const;

  int partition(std::vector<int> &data, const int left, const int right) const;
};

#endif
