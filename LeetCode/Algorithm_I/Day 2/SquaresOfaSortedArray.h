#ifndef ALGORITHM_I_SQUARESOFASORTEDARRAY_H
#define ALGORITHM_I_SQUARESOFASORTEDARRAY_H

#include <vector>

using std::vector;

class SquaresOfSaSortedArray {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;
        int it = end;

        vector<int> result(nums.size());

        while (start <= end) {
            int num1 = nums[start] * nums[start];
            int num2 = nums[end] * nums[end];

            if (num1 > num2) {
                result[it] = num1;
                ++start;
            } else {
                result[it] = num2;
                --end;
            }
            --it;
        }
        return result;
    }
};

#endif//ALGORITHM_I_SQUARESOFASORTEDARRAY_H
