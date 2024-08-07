#include "jump-game.hpp"

bool JumpGame::canJump(std::vector<int>& nums) const {
    if (nums.size() <= 1) {
        return true;
    }

    int target = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] + i >= target) {
            target = i;
        }
    }

    return target == 0;
}