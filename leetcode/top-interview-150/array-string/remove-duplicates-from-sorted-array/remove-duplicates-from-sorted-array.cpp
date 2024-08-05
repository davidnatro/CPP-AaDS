#include "remove-duplicates-from-sorted-array.hpp"

int RemoveDuplicatesFromSortedArray::removeDuplicates(std::vector<int>& nums) const {
    int move = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] != nums[i]) {
            nums[move] = nums[i];
            move += 1;
        }
    }
    return move;
}