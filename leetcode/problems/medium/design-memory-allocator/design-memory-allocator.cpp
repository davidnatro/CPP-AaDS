#include "design-memory-allocator.h"

Allocator::Allocator(int n) {
    if (n < 0) {
        throw std::invalid_argument("memory size cannot be negative");
    }

    this->size_ = 0;
    this->capacity_ = n;
    this->memory_ = new int[n];
    for (int i = 0; i < n; ++i) {
        this->memory_[i] = 0;
    }
}

int Allocator::allocate(int size, int m_id) {
    if (this->capacity_ - this->size_ < size) {
        return -1;
    }
    if (this->capacity_ == size && this->size_ == 0) {
        this->size_ = size;
        for (int i = 0; i < this->capacity_; ++i) {
            this->memory_[i] = m_id;
        }
        return 0;
    }

    int count;
    int position;
    bool has_space = false;
    for (int i = 0; i <= this->capacity_ - size; ++i) {
        count = 0;
        position = i;
        for (int j = i; j < i + size; ++j) {
            if (this->memory_[j] == 0) {
                if (count == 0) {
                    position = j;
                }
                count += 1;

            } else {
                count = 0;
            }
        }

        if (count == size) {
            has_space = true;
            break;
        }
    }

    if (!has_space) {
        return -1;
    }

    this->size_ += size;
    for (int i = position; i < position + size; ++i) {
        this->memory_[i] = m_id;
    }

    return position;
}

int Allocator::free(int m_id) {
    int count = 0;
    for (int i = 0; i < this->capacity_; ++i) {
        if (this->memory_[i] == m_id) {
            this->memory_[i] = 0;
            this->size_ -= 1;
            count += 1;
        }
    }
    return count;
}

Allocator::~Allocator() {
    delete[] this->memory_;
}
