#ifndef ALGORITHM_I_MIDDLEOFTHELINKEDLIST_H
#define ALGORITHM_I_MIDDLEOFTHELINKEDLIST_H


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MiddleOfTheLinkedList {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode* tail = head;

        while (tail->next != nullptr) {
            head = head->next;
            tail = tail->next;
            if (tail->next != nullptr) {
                tail = tail->next;
            }
        }

        return head;
    }
};

#endif//ALGORITHM_I_MIDDLEOFTHELINKEDLIST_H
