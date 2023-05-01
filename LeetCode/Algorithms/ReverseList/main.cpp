#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *current = head;
        ListNode *previous = nullptr;
        ListNode *next = nullptr;

        while (current != nullptr) {
            next = current->getNext();
            current->setNext(previous);

            previous = current;
            current = next;
        }

        return previous;
    }
};

int main() {
    ListNode *list = new ListNode(1);
    Solution *solution = new Solution;

    for (int i = 2; i <= 10; ++i) {
        list->insert(i);
        std::cout << list << "\n";
        list = solution->reverseList(list);
        std::cout << list << "\n";
        list = solution->reverseList(list);
    }

    delete list;
    delete solution;

    return 0;
}
