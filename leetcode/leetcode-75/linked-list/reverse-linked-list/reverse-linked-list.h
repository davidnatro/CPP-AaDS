#ifndef LEETCODE_LEETCODE_75_LINKED_LIST_REVERSE_LINKED_LIST_REVERSE_LINKED_LIST_H_
#define LEETCODE_LEETCODE_75_LINKED_LIST_REVERSE_LINKED_LIST_REVERSE_LINKED_LIST_H_

// https://leetcode.com/problems/reverse-linked-list/

struct ListNode {
    int val;
    ListNode* next;

    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
};

class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) const;
};

#endif
