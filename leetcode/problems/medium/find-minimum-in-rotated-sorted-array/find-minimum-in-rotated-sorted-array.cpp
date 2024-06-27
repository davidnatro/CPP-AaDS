#include "find-minimum-in-rotated-sorted-array.hpp"

int FindMinimumInRotatedSortedArray::findMin(const std::vector<int> &nums) const {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < nums[right]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return nums[left];
}
