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

    size_t max2() {
        if (right_ != nullptr) {
            Tree* current = this;

            while (current->right_->right_ != nullptr) {
                current = current->right_;
            }

            if (current->right_->left_ != nullptr) {
                Tree* temp = current->right_->left_;
                while (temp->right_ != nullptr) {
                    temp = temp->right_;
                }
                if (temp->data_ > current->data_) {
                    return temp->data_;
                }
            }

            return current->data_;
        }

        if (left_ != nullptr) {
            Tree* current = this;
            size_t max = left_->data_;
            while (current->left_ != nullptr) {
                current = current->left_;
                if (current->right_ != nullptr) {
                    if (current->right_->data_ > max) {
                        return current->right_->data_;
                    }
                }
            }

            return max;
        }

        return data_;
    }

private:
    int data_;
    int size_ = 0;

    Tree* right_ = nullptr;
    Tree* left_ = nullptr;
};

int main() {
    int input;
    cin >> input;

    Tree tree;

    while (input != 0) {
        tree.insert(input);
        cin >> input;
    }
    cout << tree.max2();

    return 0;
}
