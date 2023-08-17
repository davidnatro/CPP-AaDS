#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

struct ListNode {
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
    ~ListNode();
};

class RemoveDuplicatesFromSortedList {
public:
    ListNode* deleteDuplicates(ListNode* head);
};

#endif
