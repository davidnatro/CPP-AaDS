#ifndef ROBOT_COLLISIONS_HPP
#define ROBOT_COLLISIONS_HPP

// https://leetcode.com/problems/robot-collisions/

#include <stack>
#include <vector>

class RobotCollisions {
public:
    std::vector<int> survivedRobotsHealths(const std::vector<int>& positions,
                                           std::vector<int>& healths,
                                           const std::string& directions) const;
};

#endif