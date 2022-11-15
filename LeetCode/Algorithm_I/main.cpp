#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "Day 1/BinarySearch.h"
#include "Day 1/FirstBadVersion.h"
#include "Day 1/SearchInsertPosition.h"

#include "Day 2/RotateArray.h"
#include "Day 2/SquaresOfaSortedArray.h"

#include "Day 3/MoveZeroes.h"
#include "Day 3/TwoSumII.h"

#include "Day 4/ReverseString.h"
#include "Day 4/ReverseWordsInAStringIII.h"

#include "Day 5/MiddleOfTheLinkedList.h"
#include "Day 5/RemoveNthNodeLL.h"

using std::cout;
using std::vector;

int main() {
    ListNode *head = new ListNode;
    head->val = 1;
    ListNode * temp = head;
    for (int i = 1; i <= 4; ++i) {
        temp->next = new ListNode;
        temp = temp->next;
        temp->val = i + 1;
    }

    RemoveNthNodeLL removeNthNodeLl;
    ListNode *res = removeNthNodeLl.removeNthFromEnd(head, 2);
    while (res != nullptr) {
        cout << res->val << "\t";
        res = res->next;
    }


    return 0;
}
