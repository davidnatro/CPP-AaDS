/*
 * LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 *
 */

#ifndef LRUCACHE_LRUCACHE_H
#define LRUCACHE_LRUCACHE_H

#include <iostream>
#include <map>
#include <list>

/**
 * https://leetcode.com/problems/lru-cache/description/
 */
class LRUCache {
    std::list<int> values_;
    std::map<int, std::list<int>::iterator> data_;

    int max_data_size_;

public:
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);
};

#endif  // LRUCACHE_LRUCACHE_H
