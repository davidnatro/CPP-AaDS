#ifndef GAS_STATION_HPP
#define GAS_STATION_HPP

// https://leetcode.com/problems/gas-station/

#include <vector>

class GasStation {
public:
    int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) const;
};

#endif