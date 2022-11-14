#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int size = (int) nums.size();
        int moveIndex = 1;
        for (int i = 1; i < size; ++i) {
            if (nums[i - 1] != nums[i]) {
                nums[moveIndex] = nums[i];
                ++moveIndex;
            }
        }

        return moveIndex;
    }
};

#include <iostream>

using std::cout;

int main() {
    vector<int> vector1;

    Solution solution;

    for (int i = -100; i <= 100; ++i) {
        for (int j = 0; j < 10; ++j) {
            vector1.push_back(i);
        }
    }

    int size = solution.removeDuplicates(vector1);

    for (int i = 0; i < size; ++i) {
        cout << vector1[i] << "\t";
        cout.flush();
    }
}