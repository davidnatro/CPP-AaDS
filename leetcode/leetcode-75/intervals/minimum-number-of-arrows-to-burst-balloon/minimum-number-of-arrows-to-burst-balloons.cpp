#include "minimum-number-of-arrows-to-burst-balloons.hpp"

int MinimumNumberOfArrowsToBurstBalloons::findMinArrowShots(std::vector<std::vector<int>> &points) const {
  int result = 1;
  std::sort(points.begin(),
            points.end(),
            [](const std::vector<int> &first, const std::vector<int> &second) {
              return first[1] < second[1];
            });

  int right = points[0][1];
  for (int i = 1; i < points.size(); ++i) {
    if (points[i][0] > right) {
      result += 1;
      right = points[i][1];
    }
  }

  return result;
}
