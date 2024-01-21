#include "design-hashmap.h"

MyHashMap::MyHashMap() {
    data_ = std::vector<int>(capacity_ + 1, -1);
}

int MyHashMap::get(int key) {
    return this->data_[key];
}

void MyHashMap::put(int key, int value) {
    this->data_[key] = value;
}

void MyHashMap::remove(int key) {
    this->data_[key] = -1;
}