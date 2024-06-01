#ifndef LEETCODE_PROBLEMS_MEDIUM_INSERT_DELETE_GET_RANDOM_O1_INSERT_DELETE_GET_RANDOM_O_1_HPP_
#define LEETCODE_PROBLEMS_MEDIUM_INSERT_DELETE_GET_RANDOM_O1_INSERT_DELETE_GET_RANDOM_O_1_HPP_

// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <vector>
#include <ctime>
#include <unordered_map>

class InsertDeleteGetRandomO1 {
 public:
  InsertDeleteGetRandomO1();

  bool insert(int val);

  bool remove(int val);

  int getRandom();

 private:
  std::vector<int> vector_;
  std::unordered_map<int, int> map_;
};

#endif
