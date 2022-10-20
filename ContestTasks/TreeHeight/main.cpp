#include <iostream>
#include <memory>

using std::cin;
using std::cout;

class Tree {
public:
    Tree() {
    }

    ~Tree() {
    }

    void insert(int value) {
        if (left_ == nullptr && right_ == nullptr) {
            data_ = value;
            right_ = std::shared_ptr<Tree>(new Tree());
            left_ = std::shared_ptr<Tree>(new Tree());
            return;
        }

        if (value > data_) {
            if (right_ == nullptr) {
                right_ = std::shared_ptr<Tree>(new Tree());
            }
            right_->insert(value);
        } else if (value < data_) {
            if (left_ == nullptr) {
                left_ = std::shared_ptr<Tree>(new Tree());
            }
            left_->insert(value);
        }
    }

    size_t getHeight() const {
        if (right_ == nullptr && left_ == nullptr) {
            return 0;
        }

        int height_l = right_->getHeight();
        int height_r = left_->getHeight();

        return (height_r > height_l) ? height_r + 1 : height_l + 1;
    }

private:
    int data_;

    std::shared_ptr<Tree> left_ = nullptr;
    std::shared_ptr<Tree> right_ = nullptr;
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
