#ifndef KTH_LARGEST_ELEMENT_IN_A_STREAM_HPP
#define KTH_LARGEST_ELEMENT_IN_A_STREAM_HPP

// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <set>
#include <vector>

class KthLargestElementInAStream {
public:
    KthLargestElementInAStream(int k, std::vector<int>& nums);

    int add(int val);

private:
    const int k_;
    std::multiset<int> data_;
};

#endif