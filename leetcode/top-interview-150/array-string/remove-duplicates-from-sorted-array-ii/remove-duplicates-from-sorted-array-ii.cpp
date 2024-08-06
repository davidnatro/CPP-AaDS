#include "remove-duplicates-from-sorted-array-ii.hpp"

int RemoveDuplicatesFromSortedArrayII::removeDuplicates(std::vector<int>& nums) const {
    if (nums.size() <= 2) {
        return nums.size();
    }

    int size = 0;
    int index = 0;
    for (const int element : nums) {
        if (index == 0 || index == 1 || nums[index - 2] != element) {
            nums[index] = element;
            size += 1;
            index += 1;
        }
    }

    return size;
}