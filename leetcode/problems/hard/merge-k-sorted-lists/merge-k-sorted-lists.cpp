#include "merge-k-sorted-lists.hpp"

ListNode::ListNode() : val(0), next(nullptr) { }

ListNode::ListNode(int x) : val(x), next(nullptr) { }

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) { }

ListNode *MergeKSortedLists::mergeKLists(const std::vector<ListNode *> &lists) const {
  if (lists.empty()) {
    return nullptr;
  }

  ListNode *result = lists[0];
  for (int i = 1; i < lists.size(); ++i) {
    result = this->mergeLists(result, lists[i]);
  }

  return result;
}

ListNode *MergeKSortedLists::mergeLists(ListNode *list1, ListNode *list2) const {
  if (list1 == nullptr) {
    return list2;
  }

  if (list2 == nullptr) {
    return list1;
  }

  ListNode *result = new ListNode();
  ListNode *result_head = result;

  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val <= list2->val) {
      result->next = list1;
      list1 = list1->next;
      result = result->next;
    } else {
      result->next = list2;
      list2 = list2->next;
      result = result->next;
    }
  }

  while (list1 != nullptr) {
    result->next = list1;
    list1 = list1->next;
    result = result->next;
  }

  while (list2 != nullptr) {
    result->next = list2;
    list2 = list2->next;
    result = result->next;
  }

  ListNode *list = result_head->next;
  delete result_head;

  return list;
}
