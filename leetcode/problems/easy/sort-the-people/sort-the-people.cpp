#include "sort-the-people.hpp"

std::vector<std::string> SortThePeople::sortPeople(std::vector<std::string>& names,
                                                   std::vector<int>& heights) const {
    std::vector<int> indices(names.size());
    for (int i = 0; i < names.size(); ++i) {
        indices[i] = i;
    }

    std::sort(indices.begin(), indices.end(), [&](const int first, const int second) {
        return heights[first] > heights[second];
    });

    std::vector<std::string> result(names.size());
    for (int i = 0; i < names.size(); ++i) {
        result[i] = names[indices[i]];
    }

    return result;
}