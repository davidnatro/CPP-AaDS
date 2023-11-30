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
        if (left_ == nullptr && right_ == nullptr) {
            data_ = value;
            left_ = new Tree();
            right_ = new Tree();
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

    void print() const {
        if (left_ != nullptr && right_ != nullptr) {
            left_->print();
            cout << data_ << "\n";
            right_->print();
        }
    }

private:
    int data_;

    Tree* right_ = nullptr;
    Tree* left_ = nullptr;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Tree* tree = new Tree();
    int input;
    cin >> input;

    while (input != 0) {
        tree->insert(input);
        cin >> input;
    }

    tree->print();

    delete tree;

    return 0;
}
