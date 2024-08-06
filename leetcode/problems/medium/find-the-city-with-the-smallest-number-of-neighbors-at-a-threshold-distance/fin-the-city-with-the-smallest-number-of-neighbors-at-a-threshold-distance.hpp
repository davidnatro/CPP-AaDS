#ifndef FIN_THE_CITY_WITH_THE_SMALLEST_NUMBER_OF_NEIGHBORS_AT_A_THRESHOLD_DISTANCE_HPP
#define FIN_THE_CITY_WITH_THE_SMALLEST_NUMBER_OF_NEIGHBORS_AT_A_THRESHOLD_DISTANCE_HPP

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <vector>

class FinTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance {
public:
    int findTheCity(int n, const std::vector<std::vector<int>>& edges,
                    int distance_threshold) const;
};

#endif