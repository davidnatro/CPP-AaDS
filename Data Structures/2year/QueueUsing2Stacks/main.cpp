#include <iostream>
#include <queue>
#include <deque>

/*
 * Идея:
 * https://stackoverflow.com/questions/12054415/get-min-max-in-o1-time-from-a-queue
 */

class Queue {
public:
    void push(int value) {
        data_.push(value);

        if (min_.empty()) {
            min_.push_back(value);
        } else {
            while (!min_.empty() && min_.back() > value) {
                min_.pop_back();
            }
            min_.push_back(value);
        }
    }

    int pop() {
        int value = data_.front();

        if (min_.front() == value) {
            data_.pop();
            min_.pop_front();
        } else {
            data_.pop();
        }

        return value;
    }

    int min() const {
        return min_.front();
    }

private:
    std::queue<int> data_;
    std::deque<int> min_;
};

using std::cin;
using std::cout;

int main() {
    Queue queue;
    std::string input;
    int num;

/*    int operations;
    cin >> operations;*/

    do {
        cin >> input;
        if (input == "+") {
            cin >> num;
            queue.push(num);
            cout << "Pushed: " << num << "\n";
        } else if (input == "-") {
            cout << queue.min() << " ";
            cout << queue.pop() << "\n";
        } else if (input == "exit") {
            break;
        } else {
            continue;
        }

    } while (true);

    return 0;
}
