#include "../headers/LRUCache.h"

LRUCache::LRUCache(int capacity) {
    this->max_capacity_ = capacity;
}

int LRUCache::get(int key) {
    if (!values_.count(key)) {
        return -1;
    }

    int value = (*values_[key]).second;
    frequency_.erase(values_[key]);
    values_[key] = frequency_.emplace(frequency_.begin(), std::make_pair(key, value));

    return value;
}

void LRUCache::put(int key, int value) {
    if (values_.count(key)) {
        frequency_.erase(values_[key]);
        values_[key] = frequency_.emplace(frequency_.begin(), std::make_pair(key, value));
        return;
    }

    if (frequency_.size() == max_capacity_) {
        values_.erase(frequency_.back().first);
        frequency_.pop_back();
    }

    values_[key] = frequency_.emplace(frequency_.begin(), std::make_pair(key, value));
}