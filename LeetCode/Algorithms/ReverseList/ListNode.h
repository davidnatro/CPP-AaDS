#ifndef REVERSELIST_LISTNODE_H
#define REVERSELIST_LISTNODE_H

#include <iostream>

class ListNode {
    int val_;
    ListNode *next_ = nullptr;

public:
    ListNode();

    ListNode(int x);

    ListNode(int x, ListNode *next);

    int getVal();

    ListNode *getNext();

    void setNext(ListNode *next);

    void insert(int value);

    void reverse();

    ~ListNode();

    friend std::ostream &operator<<(std::ostream &stream, const ListNode *list);
};

#endif  // REVERSELIST_LISTNODE_H
