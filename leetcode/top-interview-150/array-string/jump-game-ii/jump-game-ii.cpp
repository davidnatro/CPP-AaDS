#include "jump-game-ii.hpp"

int JumpGameII::jump(const std::vector<int>& nums) const {
    if (nums.size() <= 1) {
        return 0;
    }

    int end = 0;
    int count = 0;
    int index = 0;
    int can_jump = nums[index] + index;
    while (index < nums.size()) {
        const int can_reach = nums[index] + index;
        can_jump = std::max(can_jump, can_reach);
        if (index == end) {
            end = can_jump;
            count += 1;
            if (end >= nums.size() - 1) {
                break;
            }
        }
        index += 1;
    }

    return count;
}