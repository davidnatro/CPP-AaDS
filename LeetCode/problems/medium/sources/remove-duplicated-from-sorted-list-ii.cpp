#include "../headers/remove-duplicates-from-sorted-list-ii.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode* next) : val(x), next(next) {
}

ListNode* RemoveDuplicatesFromSortedListII::deleteDuplicatesUsingMap(ListNode* head) {
    std::map<int, bool> appeared_elements;

    ListNode* new_head = head;
    ListNode* to_delete = nullptr;
    ListNode* previous = nullptr;

    while (new_head != nullptr) {
        if (!appeared_elements.count(new_head->val)) {
            appeared_elements[new_head->val] = true;
            previous = new_head;
            new_head = new_head->next;
            continue;
        }

        if (previous != nullptr) {
            previous->next = new_head->next;
            to_delete = new_head;
            to_delete->next = nullptr;
            delete to_delete;
            new_head = previous->next;
        } else {
            to_delete = new_head;
            new_head = new_head->next;
            to_delete->next = nullptr;
            delete to_delete;
        }
    }

    return head;
}