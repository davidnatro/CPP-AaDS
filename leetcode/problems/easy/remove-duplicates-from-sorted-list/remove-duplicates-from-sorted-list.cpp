#include "remove-duplicates-from-sorted-list.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {
}

ListNode::~ListNode() {
    delete next;
}

ListNode *RemoveDuplicatesFromSortedList::deleteDuplicates(ListNode *head) {
    ListNode *to_delete;
    ListNode *temp_head = head;
    while (temp_head != nullptr) {
        if (temp_head->next != nullptr && temp_head->val == temp_head->next->val) {
            to_delete = temp_head->next;
            temp_head->next = temp_head->next->next;
            to_delete->next = nullptr;
            delete to_delete;
            to_delete = nullptr;
        } else {
            temp_head = temp_head->next;
        }
    }

    return head;
}