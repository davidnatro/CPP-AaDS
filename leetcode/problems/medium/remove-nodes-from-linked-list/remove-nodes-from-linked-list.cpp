#include "remove-nodes-from-linked-list.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode* next) : val(x), next(next) {
}

ListNode::~ListNode() {
    delete next;
}

ListNode* RemoveNodesFromLinkedList::removeNodes(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* reversed = reverse(head);
    ListNode* new_head = reversed;
    ListNode* previous = nullptr;
    ListNode* to_delete = nullptr;
    int max = reversed->val;

    while (new_head != nullptr) {
        if (new_head->val < max) {
            previous->next = new_head->next;
            to_delete = new_head;
            to_delete->next = nullptr;
            delete to_delete;
        } else {
            max = new_head->val;
            previous = new_head;
        }
        new_head = previous->next;
    }

    return reverse(reversed);
}

ListNode* RemoveNodesFromLinkedList::reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* previous = nullptr;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}