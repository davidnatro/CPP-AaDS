#ifndef ALGORITHM_I_REMOVENTHNODELL_H
#define ALGORITHM_I_REMOVENTHNODELL_H

// Definition for singly-linked list.
/*struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

class RemoveNthNodeLL {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *temp = head;
        ListNode *tail = head;
        for (int i = 0; i < n; ++i)
            tail = tail->next;


        if (tail == nullptr)
            return head->next;


        while (tail->next != nullptr) {
            head = head->next;
            tail = tail->next;
        }

        //        if (head->next != nullptr && head->next->next != nullptr)
        head->next = head->next->next;
        head = temp;

        return head;
    }
};

#endif//ALGORITHM_I_REMOVENTHNODELL_H
