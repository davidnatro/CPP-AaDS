#include "maximum-distance-in-arrays.hpp"

int MaximumDistanceInArrays::maxDistance(const std::vector<std::vector<int>>& arrays) const {
    if (arrays.empty()) {
        return 0;
    }

    int min = arrays[0][0];
    int max = arrays[0][arrays[0].size() - 1];
    int result = 0;

    for (int i = 1; i < arrays.size(); ++i) {
        const int local_min = arrays[i][0];
        const int local_max = arrays[i][arrays[i].size() - 1];

        result = std::max(result, std::max(max - local_min, local_max - min));

        min = std::min(min, local_min);
        max = std::max(max, local_max);
    }

    return result;
}