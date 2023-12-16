#include "../headers/queue-using-stacks.h"

QueueUsingStacks::QueueUsingStacks() {
}

void QueueUsingStacks::push(int x) {
    main_stack_.push(x);
}

int QueueUsingStacks::pop() {
    if (secondary_stack_.empty()) {
        transfer_data();
    }

    int result = secondary_stack_.top();
    secondary_stack_.pop();
    return result;
}

int QueueUsingStacks::peek() {
    if (secondary_stack_.empty()) {
        transfer_data();
    }

    return secondary_stack_.top();
}

bool QueueUsingStacks::empty() {
    if (secondary_stack_.empty()) {
        transfer_data();
    }

    return secondary_stack_.empty();
}

void QueueUsingStacks::transfer_data() {
    while (!main_stack_.empty()) {
        secondary_stack_.push(main_stack_.top());
        main_stack_.pop();
    }
}