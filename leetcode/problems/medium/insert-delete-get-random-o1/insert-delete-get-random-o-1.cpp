#include "insert-delete-get-random-o-1.hpp"

InsertDeleteGetRandomO1::InsertDeleteGetRandomO1() {
  std::srand(std::time(nullptr));
}

bool InsertDeleteGetRandomO1::insert(int val) {
  if (this->map_.count(val)) {
    return false;
  }

  this->vector_.push_back(val);
  this->map_[val] = this->vector_.size() - 1;
  return true;
}

bool InsertDeleteGetRandomO1::remove(int val) {
  if (!this->map_.count(val)) {
    return false;
  }

  int index = this->map_[val];
  this->vector_[index] = this->vector_.back();
  this->vector_.pop_back();
  this->map_[this->vector_[index]] = index;
  this->map_.erase(val);
  return true;
}

int InsertDeleteGetRandomO1::getRandom() {
  return this->vector_[std::rand() % this->vector_.size()];
}
