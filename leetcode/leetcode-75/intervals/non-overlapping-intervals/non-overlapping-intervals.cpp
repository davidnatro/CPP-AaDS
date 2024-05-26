#include "non-overlapping-intervals.hpp"

int NonOverlappingIntervals::eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) const {
  int result = 0;
  std::sort(intervals.begin(), intervals.end());

  for (int i = 0; i < intervals.size() - 1; ++i) {
    if (intervals[i + 1][0] >= intervals[i][0] && intervals[i + 1][1] <= intervals[i][1]) {
      result += 1;
    } else if (intervals[i + 1][0] < intervals[i][1]) {
      result += 1;
      intervals[i + 1][0] = intervals[i][0];
      intervals[i + 1][1] = intervals[i][1];
    }
  }
  return result;
}
