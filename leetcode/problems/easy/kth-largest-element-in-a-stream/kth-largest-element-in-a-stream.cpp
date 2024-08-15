#include "kth-largest-element-in-a-stream.hpp"

KthLargestElementInAStream::KthLargestElementInAStream(int k, std::vector<int>& nums) : k_(k) {
    for (const int num : nums) {
        data_.emplace(num);
    }
}

int KthLargestElementInAStream::add(int val) {
    data_.emplace(val);
    int count = 1;
    auto it = data_.end();
    --it;
    while (count != k_) {
        --it;
        count += 1;
    }
    return *it;
}