#ifndef LEETCODE_LEETCODE_75_LINKED_LIST_MAXIMUM_TWIN_SUM_OF_A_LINKED_LIST_MAXIMUM_TWIN_SUM_OF_A_LINKED_LIST_H_
#define LEETCODE_LEETCODE_75_LINKED_LIST_MAXIMUM_TWIN_SUM_OF_A_LINKED_LIST_MAXIMUM_TWIN_SUM_OF_A_LINKED_LIST_H_

// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

struct ListNode {
    int val;
    ListNode* next;

    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
};

class MaximumTwinSumOfALinkedList {
public:
    int pairSum(ListNode* head) const;
};

#endif
