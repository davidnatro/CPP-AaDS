#include <iostream>
#include <stack>

class Queue {
public:
    void push(int value) {
        stack1_.push(value);
    }

    int pop() {
        if (stack2_.empty()) {
            while (!stack1_.empty()) {
                stack2_.push(stack1_.top());
                stack1_.pop();
            }
        }

        int value = stack2_.top();
        stack2_.pop();

        return value;
    }

    int min() const {
        return min_number_;
    }

private:
    std::stack<int> stack1_;
    std::stack<int> stack2_;

    int min_number_;
};

using std::cin;
using std::cout;

int main() {
    Queue queue;
    std::string input;
    int num;

    int operations;
    cin >> operations;
    int i = 0;

    do {
        cin >> input;
        if (input == "+") {
            cin >> num;
            queue.push(num);
            cout << "Pushed: " << num << "\n";
        } else if (input == "-") {
            cout << queue.min() << " ";
            cout << queue.pop() << "\n";
        } else {
            return 0;
        }
        ++i;
    } while (i < operations);

    return 0;
}
