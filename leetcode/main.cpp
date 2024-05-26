#include <iostream>
#include "leetcode-75/intervals/minimum-number-of-arrows-to-burst-balloon/minimum-number-of-arrows-to-burst-balloons.hpp"

int main() {
  MinimumNumberOfArrowsToBurstBalloons minimum_number_of_arrows_to_burst_balloons;
  std::vector<std::vector<int>> data = {{ 10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 }};
  std::cout << minimum_number_of_arrows_to_burst_balloons.findMinArrowShots(data) << " 2" << "\n";
  data = {{ 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 }};
  std::cout << minimum_number_of_arrows_to_burst_balloons.findMinArrowShots(data) << " 4" << "\n";
  data = {{ 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }};
  std::cout << minimum_number_of_arrows_to_burst_balloons.findMinArrowShots(data) << " 2" << "\n";
  data = {{ 9, 12 }, { 1, 10 }, { 4, 11 }, { 8, 12 }, { 3, 9 }, { 6, 9 }, { 6, 7 }};
  std::cout << minimum_number_of_arrows_to_burst_balloons.findMinArrowShots(data) << " 2" << "\n";
  return 0;
}
