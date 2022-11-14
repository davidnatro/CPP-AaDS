#ifndef ALGORITHM_I_ROTATEARRAY_H
#define ALGORITHM_I_ROTATEARRAY_H

#include <vector>

using std::vector;

// [1,2,3,4,5,6,7] -> 7

class RotateArray {
public:
    void rotate(vector<int> &nums, int k) {
        int rotations = k % nums.size();

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + rotations);
        std::reverse(nums.begin() + rotations, nums.end());
    }
};

#endif//ALGORITHM_I_ROTATEARRAY_H
