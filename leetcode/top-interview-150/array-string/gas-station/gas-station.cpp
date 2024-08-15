#include "gas-station.hpp"

int GasStation::canCompleteCircuit(const std::vector<int>& gas,
                                   const std::vector<int>& cost) const {
    const int size = gas.size();
    int gas_sum = 0;
    int cost_sum = 0;

    for (int i = 0; i < size; ++i) {
        gas_sum += gas[i];
        cost_sum += cost[i];
    }

    if (cost_sum > gas_sum) {
        return -1;
    }

    int index = 0;
    int current_gas = 0;
    for (int i = 0; i < size; ++i) {
        current_gas += (gas[i] - cost[i]);
        if (current_gas < 0) {
            current_gas = 0;
            index = i + 1;
        }
    }

    return index;
}