#include "find-first-and-last-position-of-element-in-sorted-array.h"

std::vector<int> FindFirstAndLastPositionOfElementInSortedArray::searchRange(
    const std::vector<int> &nums, int target) {
    int index = binarySearch(nums, target);

    if (index == -1) {
        return std::vector<int>{-1, -1};
    }

    int left = index;
    int right = index;

    while (left >= 0 && nums[left] == target) {
        left -= 1;
    }

    while (right < nums.size() && nums[right] == target) {
        right += 1;
    }

    return std::vector<int>{left + 1, right - 1};
}

int FindFirstAndLastPositionOfElementInSortedArray::binarySearch(const std::vector<int> &nums,
                                                                 int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left <= right) {
        mid = (static_cast<unsigned int>(left) + static_cast<unsigned int>(right)) >> 1;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
