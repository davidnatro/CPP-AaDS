#include "product-of-array-except-self.h"

std::vector<int> ProductOfArrayExceptSelf::productExceptSelf(const std::vector<int> &nums) const {
    if (nums.size() < 2) {
        return nums;
    }

    std::vector<int> result(nums.size(), 1);

    result[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        result[i] = nums[i] * result[i - 1];
    }

    int right_product = nums[nums.size() - 1];
    result[result.size() - 1] = result[result.size() - 2];
    for (int i = nums.size() - 2; i > 0; --i) {
        result[i] = result[i - 1] * right_product;
        right_product *= nums[i];
    }
    result[0] = right_product;

    return result;
}
