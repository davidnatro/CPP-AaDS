#include "linked-list-cycle.hpp"

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

bool LinkedListCycle::hasCycle(ListNode* head) const {
    if (head == nullptr) {
        return false;
    }

    const ListNode* slow = head;
    const ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
}