#ifndef LEETCODE_PROBLEMS_HEADERS_REVERSELINKEDLIST_H_
#define LEETCODE_PROBLEMS_HEADERS_REVERSELINKEDLIST_H_

// https://leetcode.com/submissions/detail/919386023/

struct ListNode {
    int val;
    ListNode *next;

    ListNode();
    explicit ListNode(int x);
    ListNode(int x, ListNode *next);

    ~ListNode();
};

class Solution {
public:
    ListNode *reverseList(ListNode *head);
};

#endif
