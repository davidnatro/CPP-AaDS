#include <iostream>
#include <string>
// #include "CheckRbTree.h"
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
    Node<T> *root = nullptr;

    RBTree() {
        root = nullptr;
    }

    RBTree(std::initializer_list<T> list) {
        size_ = list.size();

        for (const T *it = list.begin(); it != list.end(); ++it) {
            insert(*it);
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

        insert(root, key);
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
        inOrderLowerBound(root, key, result);
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

    void insert(Node<T> *&root, int key) {
        Node<T> *node = new Node<T>();
        node->key = key;

        Node<T> *current = root;
        Node<T> *parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (node->key < current->key) {
                current = current->left;
            } else if (node->key > current->key) {
                current = current->right;
            } else {
                delete node;
                size_ -= 1;
                return;
            }
        }

        node->parent = parent;
        if (node->key < parent->key) {
            parent->left = node;
        } else {
            parent->right = node;
        }

        balance(root, node);
    }

    void setColor(Node<T> *node, Color color) {
        if (node != nullptr) {
            node->color = color;
        }
    }

    void rotateLeft(Node<T> *&root, Node<T> *node) {
        Node<T> *right = node->right;
        node->right = right->left;

        if (right->left != nullptr) {
            right->left->parent = node;
        }

        right->parent = node->parent;
        if (node->parent == nullptr) {
            root = right;
        } else if (node->parent->left == node) {
            node->parent->left = right;
        } else {
            node->parent->right = right;
        }

        right->left = node;
        node->parent = right;
    }

    void rotateRight(Node<T> *&root, Node<T> *node) {
        Node<T> *left = node->left;
        node->left = left->right;

        if (left->right != nullptr) {
            left->right->parent = node;
        }

        left->parent = node->parent;
        if (node->parent == nullptr) {
            root = left;
        } else if (node->parent->right == node) {
            node->parent->right = left;
        } else {
            node->parent->left = left;
        }

        left->right = node;
        node->parent = left;
    }

    void balance(Node<T> *&root, Node<T> *node) {
        if (node->parent == nullptr) {
            node->color = Color::BLACK;
            return;
        }

        if (node->parent->color == Color::BLACK) {
            return;
        }

        Node<T> *grandparent = getGrandparent(node);
        Node<T> *uncle = getUncle(node);

        if (uncle != nullptr) {
            if (uncle->color == Color::RED) {
                recolor(grandparent);
                balance(root, grandparent);
                return;
            }
        }

        if (node->parent->right == node && grandparent->left == node->parent) {
            rotateLeft(root, node->parent);
            node = node->left;
        } else if (node->parent->left == node && grandparent->right == node->parent) {
            rotateRight(root, node->parent);
            node = node->right;
        }

        if (node->parent->left == node) {
            rotateRight(root, grandparent);
        } else {
            rotateLeft(root, grandparent);
        }

        node->parent->color = Color::BLACK;
        grandparent->color = Color::RED;
    }

    void recolor(Node<T> *node) {
        if (node == nullptr) {
            return;
        }

        if (node->left->color == Color::RED && node->right->color == Color::RED) {
            setColor(node, Color::RED);
            setColor(node->left, Color::BLACK);
            setColor(node->right, Color::BLACK);
            if (node == root) {
                setColor(node, Color::BLACK);
            }
        }
    }

    Node<T> *getGrandparent(const Node<T> *node) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->parent == nullptr) {
            return nullptr;
        }

        return node->parent->parent;
    }

    Node<T> *getUncle(const Node<T> *node) const {
        Node<T> *grandparent = getGrandparent(node);
        if (grandparent == nullptr) {
            return nullptr;
        }

        return (node->parent == grandparent->left) ? grandparent->right : grandparent->left;
    }

    void inOrderLowerBound(Node<T> *root, T key, T *&result) const {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            inOrderLowerBound(root->left, key, result);
        }

        if (root->key >= key) {
            if (result != nullptr) {
                if (root->key < *result) {
                    result = &root->key;
                    return;
                }
            } else {
                result = &root->key;
                return;
            }
        }

        if (root->right != nullptr) {
            inOrderLowerBound(root->right, key, result);
        }
    }

    void destroy(Node<T> *node) {
        if (node == nullptr) {
            return;
        }

        destroy(node->left);
        destroy(node->right);

        delete node;
    }
};

using std::cin;
using std::cout;
#include "Utils.h"

int main() {
    RBTree<int> *rb_tree = new RBTree<int>(/*{2, 0, 3, 1, 4, 6, 7, 8}*/);

    srand(time(nullptr));

    for (int i = 0; i < 10; ++i) {
        int number = Utils::getRandomNumber(0, 1000);
        if (rb_tree->find(number) != nullptr) {
            --i;
            continue;
        }
        rb_tree->insert(number);
    }

    delete rb_tree;

    return 0;
}
