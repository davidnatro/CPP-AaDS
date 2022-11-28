#include <iostream>

using std::cin;
using std::cout;

struct Node {
    Node *left = nullptr;
    Node *right = nullptr;

    int height = 0;
    int value;

    ~Node() {
        delete left;
        delete right;
    }
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
        Node *current = root_;

        while (current != nullptr) {
            if (value > current->value) {
                current = current->right;
            } else if (value < current->value) {
                current = current->left;
            } else {
                return ;
            }
        }
    }

    int *find(int value) {
        Node *current = root_;
        while (current != nullptr) {
            if (value > current->value) {
                current = current->right;
            } else if (value < current->value) {
                current = current->left;
            } else {
                return reinterpret_cast<int *>(current->value);
            }
        }

        return nullptr;
    }

    int *traversal() {
        int *result = new int[getSize()];
        inOrderToArray(root_, result);

        return result;
    }

    int *lowerBound(int value) {
        int *result;
        inOrderLowerBound(root_, value, result);

        return result;
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
        delete root_;
    }

private:
    Node *root_ = nullptr;

    size_t getHeight(const Node *node) const {
        if (node == nullptr) {
            return 0;
        }

        int height_l = 1;
        int height_r = 1;

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
        Node *current = node;

        while (current != nullptr) {
            if (value > current->value) {
                current = current->right;
            } else if (value < current->value) {
                current = current->left;
            } else {
                return nullptr;
            }
        }
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

    void inOrderLowerBound(const Node *node, int value, int *result) const {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            inOrderLowerBound(node->left, value, result);
        }

        if (node->value >= value) {
            result = reinterpret_cast<int *>(node->value);
            return;
        }

        if (node->right != nullptr) {
            inOrderLowerBound(node->right, value, result);
        }
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

    cout << "size: " << tree->getSize() << "\n";
    cout << "height: " << tree->getHeight();

    delete tree;

    return 0;
}
