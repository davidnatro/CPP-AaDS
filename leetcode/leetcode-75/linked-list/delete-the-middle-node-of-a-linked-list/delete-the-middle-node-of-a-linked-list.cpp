#include "delete-the-middle-node-of-a-linked-list.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {
}

ListNode *DeleteTheMiddleNodeOfALinkedList::deleteMiddle(ListNode *head) const {
    if (head == nullptr) {
        return nullptr;
    }

    int size = 1;
    ListNode *head_copy = head;
    while (head_copy->next != nullptr) {
        size += 1;
        head_copy = head_copy->next;
    }

    int middle = size / 2;
    if (middle == 0) {
        delete head;
        return nullptr;
    }

    head_copy = head;
    for (int i = 0; i < middle - 1; ++i) {
        head_copy = head_copy->next;
    }
    ListNode *to_delete = head_copy->next;
    head_copy->next = to_delete->next;
    delete to_delete;

    return head;
}
