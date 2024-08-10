#include "h-index.hpp"

int HIndex::hIndex(std::vector<int>& citations) const {
    std::sort(citations.begin(), citations.end());

    int max = 0;
    const int size = citations.size();
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] >= size - i) {
            max = std::max(max, size - i);
        }
    }

    return max;
}