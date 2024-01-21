#include "merge-two-sorted-lists.h"

ListNode::ListNode() : val(0), next(nullptr) {
}

ListNode::ListNode(int x) : val(x), next(nullptr) {
}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {
}

ListNode::~ListNode() {
    delete next;
}

ListNode *MergeTwoSortedLists::mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *new_list_begin = new ListNode();
    ListNode *new_list = new_list_begin;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            new_list->next = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            new_list->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        new_list = new_list->next;
    }

    if (list1 == nullptr) {
        new_list->next = list2;
    }

    if (list2 == nullptr) {
        new_list->next = list1;
    }

    ListNode *result = new_list_begin->next;

    new_list_begin->next = nullptr;
    delete new_list_begin;

    return result;
}