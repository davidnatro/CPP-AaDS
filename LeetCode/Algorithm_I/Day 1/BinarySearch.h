#ifndef ALGORITHM_I_BINARYSEARCH_H
#define ALGORITHM_I_BINARYSEARCH_H

#include <vector>

using std::vector;

class BinarySearch {
public:
    int search(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            }
        }

        return -1;
    }
};

#endif//ALGORITHM_I_BINARYSEARCH_H
