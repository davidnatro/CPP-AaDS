#include <iostream>

#include "problems/headers/MergeTwoSortedLists.h"

int main() {
    Solution * solution = new Solution;
    ListNode* first = new ListNode();
    first->val = 1;
    first->next = new ListNode(2);
    first->next->next = new ListNode(4);

    ListNode* second = new ListNode();
    second->val = 1;
    second->next = new ListNode(3);
    second->next->next = new ListNode(4);

    ListNode *heh = solution->mergeTwoLists(first, second);

    while (heh != nullptr) {
        std::cout << heh->val << '\t';
        heh = heh->next;
    }

    delete solution;
    delete heh;

    return 0;
}
