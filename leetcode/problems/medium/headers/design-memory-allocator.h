#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_DESIGN_MEMORY_ALLOCATOR_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_DESIGN_MEMORY_ALLOCATOR_H_

// https://leetcode.com/problems/design-memory-allocator/

#include <stdexcept>

class Allocator {
    int *memory_;
    int size_;
    int capacity_;

public:
    Allocator(int n);

    int allocate(int size, int m_id);

    int free(int m_id);

    ~Allocator();
};

#endif
