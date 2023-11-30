#include <iostream>
#include <deque>

class Deque {
public:
    Deque() {
    }

    void pushBack(int value) {
        data_.push_back(value);
    }

    void pushMiddle(int value) {
        int index = size() % 2 == 0 ? size() / 2 : size() / 2 + 1;
        data_.insert(data_.begin() + index, value);
    }

    int popFront() {
        int value = data_[0];
        data_.pop_front();
        return value;
    }

    int front() const {
        return data_[0];
    }

    int back() const {
        return data_[size() - 1];
    }

    size_t size() const {
        return data_.size();
    }

    ~Deque() {
    }

private:
    std::deque<int> data_;
};

using std::cin;
using std::cout;

int main() {
    std::string input;
    Deque deque;
    int num;

    do {
        cin >> input;
        if (input == "+") {
            cin >> num;
            deque.pushBack(num);
        } else if (input == "*") {
            cin >> num;
            deque.pushMiddle(num);
        } else if (input == "-") {
            cout << deque.popFront() << "\n";
        } else if (input == "exit") {
            return 0;
        } else {
            cout << "Incorrect input!"
                 << "\n";
            continue;
        }
    } while (true);

    return 0;
}