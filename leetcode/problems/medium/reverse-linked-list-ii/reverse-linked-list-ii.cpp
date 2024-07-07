#include "reverse-linked-list-ii.hpp"

ListNode::ListNode(): val(0), next(nullptr) {
}

ListNode::ListNode(int x): val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode* next): val(x), next(next) {
}

ListNode* ReverseLinkedListII::reverseBetween(ListNode* head, int left, int right) const {
    if (left == right) {
        return head;
    }

    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* dummy = new ListNode(0, head);
    ListNode* left_reverse = dummy;

    while (left > 1) {
        left_reverse = left_reverse->next;
        left -= 1;
    }

    ListNode* right_reverse = head;

    while (right > 1) {
        right_reverse = right_reverse->next;
        right -= 1;
    }

    ListNode* start = left_reverse;
    ListNode* end = right_reverse->next;
    left_reverse = left_reverse->next;
    start->next = nullptr;
    right_reverse->next = nullptr;

    ListNode* reversed = this->reverseLinkedList(left_reverse);
    start->next = reversed;
    while (reversed->next != nullptr) {
        reversed = reversed->next;
    }
    reversed->next = end;

    start = dummy->next;
    dummy->next = nullptr;
    delete dummy;

    return start;
}

ListNode* ReverseLinkedListII::reverseLinkedList(ListNode* head) const {
    ListNode* current = head;
    ListNode* previous = nullptr;

    while (current != nullptr) {
        ListNode* next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }

    return previous;
}