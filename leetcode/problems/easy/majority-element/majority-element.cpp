#include "majority-element.hpp"

int MajorityElement::majorityElement(const std::vector<int>& nums) const {
    int votes = 0;
    int element = -1;

    for (int i = 0; i < nums.size(); ++i) {
        if (votes == 0) {
            element = nums[i];
            votes += 1;
        } else if (element == nums[i]) {
            votes += 1;
        } else {
            votes -= 1;
        }
    }

    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == element) {
            count += 1;
        }
    }

    if (count > nums.size() / 2) {
        return element;
    }

    return -1;
}