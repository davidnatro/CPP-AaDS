#ifndef ALGORITHM_I_SEARCHINSERTPOSITION_H
#define ALGORITHM_I_SEARCHINSERTPOSITION_H

#include <vector>

using std::vector;

class SearchInsertPosition {
public:
    int searchInsert(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            int num = nums[mid];

            if (num == target) {
                return mid;
            }

            if (num > target) {
                high = mid - 1;
            } else if (num < target) {
                low = mid + 1;
            }
        }

        return high + 1;
    }
};

#endif//ALGORITHM_I_SEARCHINSERTPOSITION_H
