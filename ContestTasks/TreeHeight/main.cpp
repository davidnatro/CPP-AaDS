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

    size_t getHeight() const {
        if (left_ == nullptr && right_ == nullptr) {
            return 0;
        }

        int height_l, height_r;

        if (left_ != nullptr) {
            height_l = left_->getHeight();
        }

        if (right_ != nullptr) {
            height_r = right_->getHeight();
        }
        return (height_r > height_l) ? height_r + 1 : height_l + 1;
    }

private:
    int data_;

    Tree* right_ = nullptr;
    Tree* left_ = nullptr;
};

int main() {
    int input;
    cin >> input;

    Tree tree;

    while (input != 0) {
        cin >> input;
        tree.insert(input);
    }
    cout << tree.getHeight();

    return 0;
}
