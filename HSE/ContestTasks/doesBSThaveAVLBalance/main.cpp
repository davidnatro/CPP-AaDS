#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

class Tree {
public:
    Tree() {
    }

    ~Tree() {
        delete left_;
        delete right_;
    }

    void insert(int value) {
        if (is_empty_) {
            data_ = value;
            is_empty_ = false;
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

    Tree *right_ = nullptr;
    Tree *left_ = nullptr;

private:
    bool is_empty_ = true;
    int data_;
};

// Решение с 5 контеста.
int getHeight(Tree *node) {
    if (node == nullptr) {
        return 0;
    }

    int height_l = getHeight(node->left_);
    if (height_l == -1) {
        return -1;
    }

    int height_r = getHeight(node->right_);
    if (height_r == -1) {
        return -1;
    }

    return abs(height_r - height_l) <= 1 ? std::max(height_l, height_r) + 1 : -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Tree *tree = new Tree();
    int input;
    cin >> input;

    while (input != 0) {
        tree->insert(input);
        cin >> input;
    }

    if (getHeight(tree) >= 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    delete tree;

    return 0;
}
