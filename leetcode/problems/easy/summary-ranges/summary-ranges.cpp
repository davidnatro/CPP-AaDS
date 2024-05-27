#include "summary-ranges.hpp"

std::vector<std::string> SummaryRanges::summaryRanges(const std::vector<int> &nums) const {
  std::vector<std::string> result;

  std::stringstream stream;

  int i = 0;
  int j = 1;

  while (j <= nums.size()) {
    if (j < nums.size() && nums[j - 1] + 1 == nums[j]) {
      j += 1;
      continue;
    }

    if (i != j - 1) {
      stream << nums[i] << "->" << nums[j - 1];
    } else {
      stream << nums[i];
    }

    result.emplace_back(stream.str());
    stream.str("");
    i = j;
    j += 1;
  }

  return result;
}
