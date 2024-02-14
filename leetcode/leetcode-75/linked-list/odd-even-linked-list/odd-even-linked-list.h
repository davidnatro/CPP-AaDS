#ifndef LEETCODE_LEETCODE_75_LINKED_LIST_ODD_EVEN_LINKED_LIST_ODD_EVEN_LINKED_LIST_H_
#define LEETCODE_LEETCODE_75_LINKED_LIST_ODD_EVEN_LINKED_LIST_ODD_EVEN_LINKED_LIST_H_

// https://leetcode.com/problems/odd-even-linked-list/

struct ListNode {
    int val;
    ListNode* next;

    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
};

class OddEvenLinkedList {
public:
    ListNode* oddEvenList(ListNode* head) const;
};

#endif
