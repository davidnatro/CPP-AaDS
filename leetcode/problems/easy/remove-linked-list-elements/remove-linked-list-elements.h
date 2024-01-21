#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_REMOVE_LINKED_LIST_ELEMENTS_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_REMOVE_LINKED_LIST_ELEMENTS_H_

struct ListNode {
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
    ~ListNode();
};

class RemoveLinkedListElements {
public:
    ListNode* removeElements(ListNode* head, int val);
};

#endif
