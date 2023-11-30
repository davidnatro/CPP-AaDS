#include <iostream>
#include <stack>

// #include <fstream>
// std::ifstream f_in("../input.txt");

using std::cin;
using std::cout;

// C 1-го контеста
class Queue {
public:
    void push(int16_t value) {
        if (stack_.empty()) {
            stack_.emplace(value, value);
        } else {
            stack_.emplace(value, std::min(value, stack_.top().second));
        }
    }

    void pop() {
        if (stack_temp_.empty()) {
            while (!stack_.empty()) {
                if (stack_temp_.empty()) {
                    stack_temp_.emplace(stack_.top().first, stack_.top().first);
                } else {
                    stack_temp_.emplace(stack_.top().first,
                                        std::min(stack_.top().first, stack_temp_.top().second));
                }
                stack_.pop();
            }
        }
        stack_temp_.pop();
    }

    int16_t min() const {
        if (stack_.empty() || stack_temp_.empty()) {
            return stack_.empty() ? stack_temp_.top().second : stack_.top().second;
        }

        return std::min(stack_.top().second, stack_temp_.top().second);
    }

private:
    std::stack<std::pair<int16_t, int16_t>> stack_;
    std::stack<std::pair<int16_t, int16_t>> stack_temp_;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Queue queue;
    int16_t input;

    for (int i = 0; i < k; ++i) {
        cin >> input;
        queue.push(input);
    }
    cout.flush();

    for (int i = k; i < n; ++i) {
        cout << queue.min() << " ";
        queue.pop();
        cin >> input;
        queue.push(input);
    }
    cout << queue.min();

    return 0;
}
