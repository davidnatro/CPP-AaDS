#ifndef LEETCODE_PROBLEMS_HARD_MERGE_K_SORTED_LISTS_MERGE_K_SORTED_LISTS_HPP_
#define LEETCODE_PROBLEMS_HARD_MERGE_K_SORTED_LISTS_MERGE_K_SORTED_LISTS_HPP_

// https://leetcode.com/problems/merge-k-sorted-lists/

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode();
  ListNode(int x);
  ListNode(int x, ListNode *next);
};

class MergeKSortedLists {
 public:
  ListNode *mergeKLists(const std::vector<ListNode *> &lists) const;

 private:
  ListNode *mergeLists(ListNode *list1, ListNode *list2) const;
};

#endif
