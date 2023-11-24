#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_DESIGN_HASHMAP_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_DESIGN_HASHMAP_H_

#include <vector>

class MyHashMap {
    int capacity_ = 1000000;

    std::vector<int> data_;

public:
    MyHashMap();

    void put(int key, int value);

    int get(int key);

    void remove(int key);
};

#endif
