#include "odd-even-linked-list.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {
}

ListNode *OddEvenLinkedList::oddEvenList(ListNode *head) const {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_head = even;

    while (even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }

    odd->next = even_head;
    return head;
}
