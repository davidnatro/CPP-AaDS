#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_REMOVE_NODES_FROM_LINKED_LIST_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_REMOVE_NODES_FROM_LINKED_LIST_H_

// https://leetcode.com/problems/remove-nodes-from-linked-list/

struct ListNode {
    int val;
    ListNode* next;

    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
    ~ListNode();
};

class RemoveNodesFromLinkedList {
public:
    ListNode* removeNodes(ListNode* head);

private:
    ListNode* reverse(ListNode* head);
};

#endif
