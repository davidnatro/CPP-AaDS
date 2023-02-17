#include "LRUCache.h"

LRUCache::LRUCache(int capacity) {
    if (capacity < 0) {
        throw std::runtime_error("Negative size");
    }

    max_data_size_ = capacity;
}

int LRUCache::get(int key) {
    return -1;
}

void LRUCache::put(int key, int value) {

}