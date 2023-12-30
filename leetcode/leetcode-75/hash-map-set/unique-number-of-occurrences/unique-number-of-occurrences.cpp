#include "unique-number-of-occurrences.h"

bool UniqueNumberOfOccurrences::uniqueOccurrences(const std::vector<int> &arr) const {
    std::unordered_map<int, int> occurrences;
    std::unordered_set<int> times;

    for (const int element : arr) {
        occurrences[element] += 1;
    }

    for (const std::pair<int, int> pair : occurrences) {
        if (times.count(pair.second)) {
            return false;
        }
        times.insert(pair.second);
    }

    return true;
}
