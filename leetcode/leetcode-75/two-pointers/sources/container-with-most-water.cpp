#include "../headers/container-with-most-water.h"

// (i, 0) (i, height[i])

int ContainerWithMostWater::maxArea(const std::vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int max = INT32_MIN;
    int64_t area;

    while (left < right) {
        area = (right - left) * (std::min(height[left], height[right]));
        if (area > max) {
            max = area;
        }
        if (height[left] < height[right]) {
            left += 1;
        } else {
            right -= 1;
        }
    }

    return max;
}
