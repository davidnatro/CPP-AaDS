#include "../headers/move-zeroes.h"

void MoveZeroes::moveZeroes(std::vector<int> &nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[index] = nums[i];
            index += 1;
        }
    }

    for (int i = index; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}
