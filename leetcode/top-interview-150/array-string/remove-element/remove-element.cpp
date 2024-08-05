#include "remove-element.hpp"

int RemoveElement::removeElement(std::vector<int>& nums, int val) const {
    int size = 0;
    int index = 0;
    for (const int element : nums) {
        if (element != val) {
            nums[index] = element;
            size += 1;
            index += 1;
        }
    }
    return size;
}