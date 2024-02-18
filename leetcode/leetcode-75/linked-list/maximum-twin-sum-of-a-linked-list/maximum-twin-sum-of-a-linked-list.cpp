#include "maximum-twin-sum-of-a-linked-list.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {
}

int MaximumTwinSumOfALinkedList::pairSum(ListNode *head) const {
    if (head->next == nullptr) {
        return head->val;
    }

    int max = INT32_MIN;

    ListNode *first_list = head;
    ListNode *second_list;

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    second_list = reverseLinkedList(slow->next);
    slow->next = nullptr;

    int sum;
    while (first_list != nullptr && second_list != nullptr) {
        sum = first_list->val + second_list->val;
        if (sum > max) {
            max = sum;
        }

        first_list = first_list->next;
        second_list = second_list->next;
    }

    return max;
}

ListNode *MaximumTwinSumOfALinkedList::reverseLinkedList(ListNode *head) const {
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
