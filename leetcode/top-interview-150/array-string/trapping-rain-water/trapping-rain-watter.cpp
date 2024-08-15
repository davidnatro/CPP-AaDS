#include "trapping-rain-watter.hpp"

int TrappingRainWatter::trap(const std::vector<int>& height) const {
    int result = 0;
    int left = 0;
    int right = height.size() - 1;
    int left_max = height[left];
    int right_max = height[right];

    while (left < right) {
        if (left_max < right_max) {
            left += 1;
            left_max = std::max(left_max, height[left]);
            result += left_max - height[left];
        } else {
            right -= 1;
            right_max = std::max(right_max, height[right]);
            result += right_max - height[right];
        }
    }

    return result;
}