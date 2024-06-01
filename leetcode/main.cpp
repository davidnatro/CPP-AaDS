#include <iostream>
#include "problems/medium/permutation-in-string/permutation-in-string.hpp"

int main() {
  PermutationInString permutation_in_string;
  std::cout << std::boolalpha << permutation_in_string.checkInclusion("ab", "eidbaooo");
  return 0;
}
