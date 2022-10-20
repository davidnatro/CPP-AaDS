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

    // Если передавать на ссылку на this, то
    // shared_ptr уничтожает объект => выносим метод
    friend void print(const std::shared_ptr<Tree>& tree);

private:
    int data_;

    std::shared_ptr<Tree> left_ = nullptr;
    std::shared_ptr<Tree> right_ = nullptr;
};

void print(const std::shared_ptr<Tree>& tree) {
    if (tree->left_ != nullptr && tree->right_ != nullptr) {
        print(tree->left_);
        cout << tree->data_ << "\n";
        print(tree->right_);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::shared_ptr<Tree> tree(new Tree());
    int input;
    cin >> input;

    while (input != 0) {
        tree->insert(input);
        cin >> input;
    }

    print(tree);

    return 0;
}
