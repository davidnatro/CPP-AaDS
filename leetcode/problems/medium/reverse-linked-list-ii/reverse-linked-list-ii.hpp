#ifndef REVERSE_LINKED_LIST_II_HPP
#define REVERSE_LINKED_LIST_II_HPP

// https://leetcode.com/problems/reverse-linked-list-ii/

struct ListNode {
    int val;
    ListNode* next;

    ListNode();
    explicit ListNode(int x);
    ListNode(int x, ListNode* next);
};


class ReverseLinkedListII {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) const;

private:
    ListNode* reverseLinkedList(ListNode* head) const;
};


#endif