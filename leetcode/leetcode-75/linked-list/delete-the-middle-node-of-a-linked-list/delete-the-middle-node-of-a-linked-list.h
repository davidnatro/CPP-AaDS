#ifndef LEETCODE_LEETCODE_75_LINKED_LIST_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H_
#define LEETCODE_LEETCODE_75_LINKED_LIST_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H_

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

struct ListNode {
    int val;
    ListNode* next;

    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
};

class DeleteTheMiddleNodeOfALinkedList {
public:
    ListNode* deleteMiddle(ListNode* head) const;
};

#endif
