#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_

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

#endif  // LEETCODE_PROBLEMS_EASY_HEADERS_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_
