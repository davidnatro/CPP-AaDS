#include "../headers/reverse-linked-list.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {
}

ListNode::~ListNode() {
    delete next;
}

ListNode *Solution::reverseList(ListNode *head) {

    ListNode *current = head;
    ListNode *previous = nullptr;
    ListNode *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }

    return previous;
}
