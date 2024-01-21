#include "asteroid-collision.h"

std::vector<int> AsteroidCollision::asteroidCollision(const std::vector<int> &asteroids) const {
    std::stack<int> data;

    for (const int asteroid : asteroids) {
        if (data.empty() || asteroid > 0) {
            data.push(asteroid);
        } else {
            while (!data.empty() && data.top() > 0 && data.top() < abs(asteroid)) {
                data.pop();
            }
            if (!data.empty() && data.top() == abs(asteroid)) {
                data.pop();
            } else {
                if (data.empty() || data.top() < 0) {
                    data.push(asteroid);
                }
            }
        }
    }

    std::vector<int> result(data.size());
    for (int i = data.size() - 1; i >= 0; --i) {
        result[i] = data.top();
        data.pop();
    }

    return result;
}
