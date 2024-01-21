#include "remove-linked-list-elements.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode* next) : val(x), next(next) {
}

ListNode::~ListNode() {
    delete next;
}

ListNode* RemoveLinkedListElements::removeElements(ListNode* head, int val) {
    ListNode* temp_head;
    while (head != nullptr && head->val == val) {
        temp_head = head;
        head = head->next;
        temp_head->next = nullptr;
        delete temp_head;
    }

    if (head == nullptr) {
        return nullptr;
    }

    ListNode* previous_node = head;
    ListNode* current_node = head;

    while (current_node != nullptr) {
        if (current_node->val == val) {
            previous_node->next = current_node->next;
            current_node->next = nullptr;
            delete current_node;
            current_node = previous_node;
        }

        if (current_node == nullptr) {
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    return head;
}
