#include "find-peak-element.hpp"

int FindPeakElement::findPeakElement(const std::vector<int> &nums) const {
  if (nums.size() == 1) {
    return 0;
  } else if (nums.size() == 2) {
    return std::max_element(nums.begin(), nums.end()) - nums.begin();
  }

  int left = 0;
  int right = nums.size() - 1;
  int mid = left + (right - left) / 2;

  while (left <= right) {
    int mid_element = nums[mid];
    int left_element = (mid - 1 >= 0) ? nums[mid - 1] : INT32_MIN;
    int right_element = (mid + 1 < nums.size()) ? nums[mid + 1] : INT32_MIN;
    if (mid_element > left_element && mid_element > right_element) {
      return mid;
    }

    if (mid_element < left_element) {
      right = mid - 1;
    } else if (mid_element < right_element) {
      left = mid + 1;
    }

    mid = left + (right - left) / 2;
  }

  return mid;
}
