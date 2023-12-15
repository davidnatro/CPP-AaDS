#ifndef LEETCODE_DATA_STRUCTURE_HEADERS_LRUCACHE_H_
#define LEETCODE_DATA_STRUCTURE_HEADERS_LRUCACHE_H_

// https://leetcode.com/problems/lru-cache/

#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> values_;
    std::list<std::pair<int, int>> frequency_;

    int max_capacity_;
};

#endif
