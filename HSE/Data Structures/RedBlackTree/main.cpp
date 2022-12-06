#include <iostream>

enum class Color { RED, BLACK };

template <typename T>
struct Node {
    T key;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
    Color color = Color::RED;
};

template <typename T>
class RBTree {
public:
    Node<T> *root{};

    RBTree() {
        root = nullptr;
    }

    RBTree(std::initializer_list<T> list) {
        size_ = list.size();

        for (int i = 0; i < size_; ++i) {
            insert(list[i]);
        }
    }

    void insert(T key) {
        if (root == nullptr) {
            root = new Node<T>();
            root->key = key;
            root->color = Color::BLACK;
            size_ += 1;
            return;
        }

        root = insert(root, key);
        size_ += 1;
    }

    int size() const {
        return size_;
    }

    bool empty() const {
        return root == nullptr;
    }

    T *lowerBound(T key) const {
        T *result = nullptr;
        Node<T> *current = root;

        while (current != nullptr) {
            if (key <= current->key) {
                result = &current->key;
            }
            current = current->left;
        }

        return result;
    }

    T *find(T key) const {
        Node<T> *current = root;
        while (current != nullptr) {
            if (key > current->key) {
                current = current->right;
            } else if (key < current->key) {
                current = current->left;
            } else {
                return &current->key;
            }
        }

        return nullptr;
    }

    ~RBTree() {
        destroy(root);
    }

private:
    int size_ = 0;

    void setColor(Node<T> *node, Color color) {
        if (node != nullptr) {
            node->color = color;
        }
    }

    Node<T> *insert(Node<T> *node, int key) {
        if (root == nullptr) {
            root = new Node<T>();
            root->key = key;
            return root;
        }
    }

    Node<T> *smallLeft(Node<T> *a) {
        if (a == nullptr) {
            return nullptr;
        }

        Node<T> *b = a->right;

        a->right = b->left;
        b->left = a;

        a->height = getHeight(a);
        b->height = getHeight(b);

        return b;
    }

    Node<T> *smallRight(Node<T> *a) {
        if (a == nullptr) {
            return nullptr;
        }

        Node<T> *b = a->left;

        a->left = b->right;
        b->right = a;

        a->height = getHeight(a);
        b->height = getHeight(b);

        return b;
    }

    Node<T> *bigLeft(Node<T> *node) {
        node->right = smallRight(node->right);
        return smallLeft(node);
    }

    Node<T> *bigRight(Node<T> *node) {
        node->left = smallLeft(node->left);
        return smallRight(node);
    }

    void destroy(Node<T> *node) {
        if (root == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            destroy(node->left);
        }

        if (node->right != nullptr) {
            destroy(node->right);
        }

        delete node;
    }
};

using std::cin;
using std::cout;

int main() {
    RBTree<int> *rb_tree = new RBTree<int>();
    delete rb_tree;

    return 0;
}
