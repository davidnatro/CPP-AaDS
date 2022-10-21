#include <iostream>

using std::cin;
using std::cout;

class Tree {
public:
    Tree() {
    }

    ~Tree() {
        if (left_ != nullptr) {
            delete left_;
        }

        if (right_ != nullptr) {
            delete right_;
        }
    }

    void insert(int value) {
        if (size_ == 0) {
            data_ = value;
            ++size_;
            return;
        }

        if (value > data_) {
            if (right_ == nullptr) {
                right_ = new Tree();
            }
            right_->insert(value);
        } else if (value < data_) {
            if (left_ == nullptr) {
                left_ = new Tree();
            }
            left_->insert(value);
        }
    }

    void print() {
        if (left_ == nullptr && right_ == nullptr) {
            cout << data_ << "\n";
        }

        if (left_ != nullptr) {
            left_->print();
        }

        if (right_ != nullptr) {
            right_->print();
        }
    }

private:
    int data_;
    int size_ = 0;

    Tree* right_ = nullptr;
    Tree* left_ = nullptr;
};

// #include <fstream>
// std::ifstream f_in("../input.txt");

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Tree* tree = new Tree();
    int input;
    cin >> input;
    int count = 0;

    while (input != 0) {
        ++count;
        tree->insert(input);
        cin >> input;
    }

    if (count > 0) {
        tree->print();
    }

    delete tree;

    return 0;
}