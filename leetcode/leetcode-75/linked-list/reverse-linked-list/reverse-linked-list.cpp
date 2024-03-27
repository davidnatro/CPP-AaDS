#include "reverse-linked-list.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {
}

ListNode *ReverseLinkedList::reverseList(ListNode *head) const {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *next;
    ListNode *previous = nullptr;
    while (head != nullptr) {
        next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }

    return previous;
}
