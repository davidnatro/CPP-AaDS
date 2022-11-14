#ifndef ALGORITHM_I_MOVEZEROES_H
#define ALGORITHM_I_MOVEZEROES_H


#include <vector>

using std::vector;

class MoveZeroes {
public:
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        int nonZero_index = 0;

        for (int i = 0; i < size; ++i) {
            if (nums[i] != 0) {
                nums[nonZero_index++] = nums[i];
            }
        }

        for (int i = nonZero_index; i < size; ++i) {
            nums[i] = 0;
        }
    }
};

#endif//ALGORITHM_I_MOVEZEROES_H
