#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include <unordered_map>

struct ListNode {
    int val;
    ListNode* next;

    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);

    ~ListNode();
};

class RemoveDuplicatesFromSortedListII {
public:
    ListNode* deleteDuplicates(ListNode* head);
};

#endif
