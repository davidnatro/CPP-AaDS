#include <iostream>
#include <vector>
#include <set>

class Solution {
private:
    std::set<int> unique_;

public:
    int removeDuplicates(std::vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (unique_.find(nums[i]) == unique_.end()) {
                unique_.insert(nums[i]);
            } else {
                for (int j = i; j < size - 1; ++j) {
                    nums[j] = nums[j + 1];
                }
            }
        }

        return unique_.size();
    }
};

int main() {
    std::vector<int> nums;
    for (int i = 0; i < 5; ++i) {
        nums.push_back(i + 1);
        nums.push_back(i + 1);
        nums.push_back(i + 1);
    }

    for (const int& num : nums) {
        std::cout << num << "\t";
    }
    std::cout << "\n";

    Solution solution;
    int size = solution.removeDuplicates(nums);
    for (int i = 0; i < size; ++i) {
        std::cout << nums[i] << "\t";
    }

    return 0;
}
