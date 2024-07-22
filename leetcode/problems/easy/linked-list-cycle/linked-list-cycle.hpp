#ifndef LINKED_LIST_CYCLE_HPP
#define LINKED_LIST_CYCLE_HPP

// https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x);
};

class LinkedListCycle {
public:
    bool hasCycle(ListNode* head) const;
};

#endif //LINKED_LIST_CYCLE_HPP