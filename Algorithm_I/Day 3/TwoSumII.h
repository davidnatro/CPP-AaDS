#ifndef ALGORITHM_I_TWOSUMII_H
#define ALGORITHM_I_TWOSUMII_H

#include <vector>

using std::vector;

class TwoSumII {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result(2, 0);

        int start = 0;
        int end = numbers.size() - 1;

        while (start <= end) {
            int temp_res = numbers[start] + numbers[end];
            if (temp_res == target) {
                result[0] = start + 1;
                result[1] = end + 1;

                return result;
            }

            if (temp_res > target) {
                --end;
            } else if (temp_res < target) {
                ++start;
            }
        }

        return result;
    }
};

#endif//ALGORITHM_I_TWOSUMII_H
