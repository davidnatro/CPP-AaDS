#include <iostream>

using std::cin;
using std::cout;

struct Node {
    Node *left = nullptr;
    Node *right = nullptr;

    int height = 1;
    int value;
};

class AVLTree {
public:
    AVLTree() {
    }

    int getHeight() {
        return getHeight(root_);
    }

    void insert(int value) {
        root_ = insert(root_, value);
    }

    void erase(int value) {
        root_ = erase(root_, value);
    }

    int *find(int value) {
        Node *current = root_;
        while (current != nullptr) {
            if (value > current->value) {
                current = current->right;
            } else if (value < current->value) {
                current = current->left;
            } else {
                delete find_result_;
                find_result_ = new int(current->value);
                return find_result_;
            }
        }

        return nullptr;
    }

    int *traversal() {
        delete[] array_;

        if (root_ == nullptr) {
            return nullptr;
        }

        array_ = new int[getSize()];
        inOrderToArray(root_, array_);

        return array_;
    }

    int *lowerBound(int value) {
        delete lower_bound_result_;
        lower_bound_result_ = nullptr;

        lower_bound_result_ = inOrderLowerBound(root_, value, lower_bound_result_);

        return lower_bound_result_;
    }

    bool empty() {
        return root_ == nullptr;
    }

    Node *getRoot() {
        return root_;
    }

    int getSize() {
        return size(root_);
    }

    ~AVLTree() {
        destructor(root_);
        delete lower_bound_result_;
        delete[] array_;
        delete find_result_;
    }

private:
    Node *root_ = nullptr;
    int *lower_bound_result_ = nullptr;
    int *array_ = nullptr;
    int *find_result_ = nullptr;

    void destructor(Node *node) {
        if (node == nullptr) {
            return;
        }

        destructor(node->left);
        destructor(node->right);

        delete node;
    }

    size_t getHeight(const Node *node) const {
        if (node == nullptr) {
            return 0;
        }

        int height_l = 0;
        int height_r = 0;

        if (node->left != nullptr) {
            height_l = getHeight(node->left);
        }

        if (node->right != nullptr) {
            height_r = getHeight(node->right);
        }
        return (height_r > height_l) ? height_r + 1 : height_l + 1;
    }

    int size(const Node *node) const {
        if (node == nullptr) {
            return 0;
        }

        int size_l = 0;
        int size_r = 0;

        if (node->left != nullptr) {
            size_l = size(node->left);
        }

        if (node->right != nullptr) {
            size_r = size(node->right);
        }

        return size_l + size_r + 1;
    }

    int factorBalance(const Node *node) const {
        int l = (node->left == nullptr) ? 0 : node->left->height;
        int r = (node->right == nullptr) ? 0 : node->right->height;

        return l - r;
    }

    Node *insert(Node *node, const int value) {
        if (node == nullptr) {
            node = new Node();
            node->value = value;
            node->height = 1;
            return node;
        }

        if (value == node->value) {
            return node;
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else if (value < node->value) {
            node->left = insert(node->left, value);
        }

        node->height = getHeight(node);

        int factor_balance = factorBalance(node);
        if (factor_balance >= 2) {
            if (value > node->left->value) {
                return bigRight(node);
            } else if (value < node->left->value) {
                return smallRight(node);
            }
        } else if (factor_balance <= -2) {
            if (value > node->right->value) {
                return smallLeft(node);
            } else if (value < node->right->value) {
                return bigLeft(node);
            }
        }

        return node;
    }

    Node *erase(Node *node, const int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value > node->value) {
            node->right = erase(node->right, value);
        } else if (value < node->value) {
            node->left = erase(node->left, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            if (node->right == nullptr || node->left == nullptr) {
                Node *current;
                if (node->right != nullptr) {
                    current = node->right;
                    delete node;
                    node = current;
                } else if (node->left != nullptr) {
                    current = node->left;
                    delete node;
                    node = current;
                }
            } else if (node->right != nullptr && node->left != nullptr) {
                if (node->right != nullptr && node->left != nullptr) {
                    Node *current = node->right;
                    while (current->left != nullptr) {
                        current = current->left;
                    }

                    node->value = current->value;
                    node->right = erase(node->right, current->value);
                }
            }
        }

        node->height = getHeight(node);

        int balance = factorBalance(node);
        if (balance >= 2) {
            if (factorBalance(node->left) < 0) {
                return bigRight(node);
            } else if (factorBalance(node->left) >= 0) {
                return smallRight(node);
            }
        } else if (balance <= -2) {
            if (factorBalance(node->right) <= 0) {
                return smallLeft(node);
            } else if (factorBalance(node->right) > 0) {
                return bigLeft(node);
            }
        }

        return node;
    }

    Node *smallLeft(Node *a) {
        if (a == nullptr) {
            return nullptr;
        }

        Node *b = a->right;

        a->right = b->left;
        b->left = a;

        a->height = getHeight(a);
        b->height = getHeight(b);

        return b;
    }

    Node *smallRight(Node *a) {
        if (a == nullptr) {
            return nullptr;
        }

        Node *b = a->left;

        a->left = b->right;
        b->right = a;

        a->height = getHeight(a);
        b->height = getHeight(b);

        return b;
    }

    Node *bigLeft(Node *node) {
        node->right = smallRight(node->right);
        return smallLeft(node);
    }

    Node *bigRight(Node *node) {
        node->left = smallLeft(node->left);
        return smallRight(node);
    }

    int *inOrderLowerBound(const Node *node, int value, int *result) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->left != nullptr) {
            result = inOrderLowerBound(node->left, value, result);
        }

        if (node->value >= value) {
            if (result != nullptr) {
                if (node->value < *result) {
                    delete result;
                    result = new int(node->value);
                    return result;
                }
            } else {
                result = new int(node->value);
                return result;
            }
        }

        if (node->right != nullptr) {
            result = inOrderLowerBound(node->right, value, result);
        }

        return result;
    }

    void inOrderToArray(const Node *node, int *array) const {
        static int index = 0;
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            inOrderToArray(node->left, array);
        }

        array[index++] = node->value;

        if (node->right != nullptr) {
            inOrderToArray(node->right, array);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    AVLTree *tree = new AVLTree;
    tree->insert(1);
    tree->insert(-1);
    tree->insert(0);
    tree->insert(4);
    tree->insert(5);

    int size = tree->getSize();
    int *arr = tree->traversal();

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << "\t";
    }
    cout << "\n";

    cout << "size: " << tree->getSize() << "\n";
    cout << "height: " << tree->getHeight();

    delete tree;

    return 0;
}
