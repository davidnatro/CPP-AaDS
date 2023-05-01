#include "ListNode.h"

ListNode::ListNode() : val_(0) {
}

ListNode::ListNode(int x) : val_(x) {
}

ListNode::ListNode(int x, ListNode *next) {
}

int ListNode::getVal() {
    return val_;
}

ListNode *ListNode::getNext() {
    return next_;
}

void ListNode::setNext(ListNode *next) {
    this->next_ = next;
}

void ListNode::insert(int value) {
    ListNode *current = this;
    while (current->next_ != nullptr) {
        current = current->next_;
    }
    current->next_ = new ListNode(value);
}

void ListNode::reverse() {
    ListNode *current = this;
    ListNode *previous = nullptr;
    ListNode *next = nullptr;

    while (current != nullptr) {
        next = current->next_;
        current->next_ = previous;

        previous = current;
        current = next;
    }
}

ListNode::~ListNode() {
    delete next_;
}

std::ostream &operator<<(std::ostream &stream, const ListNode *list) {
    while (list != nullptr) {
        stream << list->val_ << " ";
        list = list->next_;
    }

    return stream;
}