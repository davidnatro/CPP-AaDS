#ifndef LEETCODE_MERGETWOSORTEDLISTS_H
#define LEETCODE_MERGETWOSORTEDLISTS_H

//https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;

    ListNode();
    explicit ListNode(int x);
    ListNode(int x, ListNode *next);
    ~ListNode();
};

class MergeTwoSortedLists {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);
};

#endif
