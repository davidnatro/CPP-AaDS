#include "robot-collisions.hpp"

std::vector<int> RobotCollisions::survivedRobotsHealths(const std::vector<int>& positions,
                                                        std::vector<int>& healths,
                                                        const std::string& directions) const {
    const int size = positions.size();
    if (size == 0) {
        return std::vector<int>{};
    }

    std::vector<int> indices(size);
    for (int i = 0; i < size; ++i) {
        indices[i] = i;
    }

    std::sort(indices.begin(), indices.end(), [&](const int first, const int second) {
        return positions[first] < positions[second];
    });

    std::stack<int> movement;
    for (const int index : indices) {
        if (directions[index] == 'R') {
            movement.push(index);
        } else {
            while (!movement.empty()) {
                const int top_index = movement.top();
                if (healths[index] == healths[top_index]) {
                    movement.pop();
                    healths[index] = 0;
                    healths[top_index] = 0;
                    break;
                }

                if (healths[index] < healths[top_index]) {
                    healths[index] = 0;
                    healths[top_index] -= 1;
                    if (healths[top_index] <= 0) {
                        movement.pop();
                    }
                    break;
                }

                if (healths[index] > healths[top_index]) {
                    healths[index] -= 1;
                    healths[top_index] = 0;
                    movement.pop();
                    if (healths[index] <= 0) {
                        break;
                    }
                }
            }
        }
    }

    std::vector<int> result;
    for (const int health : healths) {
        if (health > 0) {
            result.push_back(health);
        }
    }

    return result;
}