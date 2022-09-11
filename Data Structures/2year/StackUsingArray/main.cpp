#include <fstream>
#include <iostream>
#include <vector>

class Stack {
public:
    void push(int value) {
        data_.push_back(value);
    }

    int pop() {
        size_t size = data_.size();

        if (size == 0) {
            throw std::out_of_range("error");
        }

        int value = data_[size - 1];
        data_.pop_back();
        return value;
    }

    int back() const {
        size_t size = data_.size();

        if (size == 0) {
            throw std::out_of_range("error");
        }

        return data_[size - 1];
    }

    size_t size() const {
        return data_.size();
    }

    void clear() {
        data_.clear();
    }

private:
    std::vector<int> data_;
};

using std::cin;
using std::cout;

int main() {
    Stack stack;
    std::string input;
    int num;

    /*    std::ifstream f_in("input.txt");
        if (!f_in.is_open()) {
          cout << "Cannot open the file!" << "\n";
          return 0;
        }*/

    do {
        cin >> input;
        if (input == "push") {
            cin >> num;
            stack.push(num);
            cout << num << " is added to the stack"
                 << "\n";
        } else if (input == "back") {
            try {
                cout << stack.back() << " is at the top of the stack"
                     << "\n";
            } catch (const std::exception &exception) {
                cout << exception.what() << "\n";
            }
        } else if (input == "pop") {
            try {
                int returnedNum = stack.pop();
                cout << returnedNum << " is extracted from the stack"
                     << "\n";
            } catch (const std::exception &exception) {
                cout << exception.what() << "\n";
            }

        } else if (input == "size") {
            cout << stack.size() << " is stack size"
                 << "\n";
        } else if (input == "exit") {
            cout << "bye";
            return 0;
        } else {
            cout << "Incorrect input"
                 << "\n";
            continue;
        }

    } while (true);

    return 0;
}
