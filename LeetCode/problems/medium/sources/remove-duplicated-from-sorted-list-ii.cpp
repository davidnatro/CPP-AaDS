#include "../headers/remove-duplicates-from-sorted-list-ii.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode* next) : val(x), next(next) {
}

ListNode::~ListNode() {
    delete next;
}

ListNode* RemoveDuplicatesFromSortedListII::deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        return head;
    }

    std::unordered_map<int, int> frequency;

    ListNode* previous = nullptr;
    ListNode* current = head;
    ListNode* to_delete = nullptr;

    while (current != nullptr) {
        frequency[current->val] += 1;
        current = current->next;
    }

    current = head;

    while (current != nullptr) {
        if (frequency[current->val] > 1) {
            if (previous != nullptr) {
                previous->next = current->next;
                to_delete = current;
                to_delete->next = nullptr;
                delete to_delete;
                current = previous->next;
                continue;
            }

            to_delete = current;
            current = current->next;
            head = current;
            to_delete->next = nullptr;
            delete to_delete;
        } else {
            previous = current;
            current = current->next;
        }
    }

    return head;
}