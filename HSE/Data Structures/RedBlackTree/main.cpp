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
            if (current->key >= key) {
                if (result != nullptr) {
                    if (current->key < *result) {
                        result = &current->key;
                    }
                } else {
                    result = &current->key;
                }
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
            root->color = Color::RED;
            return root;
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
            node->left->parent = node;
        } else if (key > node->key) {
            node->right = insert(node->right, key);
            node->right->parent = node;
        } else {
            return node;
        }

        // Нода - родитель вставленной
        if (node->color == Color::BLACK) {
            return node;
        }

        Node<T> *brother = getBrother(node);
        if (brother != nullptr) {
            if (brother->color == Color::RED) {
                recolor(node->parent);
                return node;
            }
        }

        Node<T> *inserted_node;
        if (key > node->key) {
            inserted_node = node->right;
        } else if (key < node->key) {
            inserted_node = node->left;
        }

        Node<T> *grandparent = getGrandparent(inserted_node);
        if (inserted_node == inserted_node->parent->right &&
            inserted_node->parent == grandparent->left) {
            rotate_left(inserted_node->parent);
            inserted_node = inserted_node->left;
        } else if (inserted_node == inserted_node->parent->left &&
                   inserted_node->parent == grandparent->right) {
            rotate_right(inserted_node->parent);
            inserted_node = inserted_node->right;
        }

        return node;
    }

    void recolor(Node<T> *node) {
        if (node->left->color == Color::RED && node->right->color == Color::RED) {
            node->color = Color::RED;
            node->left->color == Color::BLACK;
            node->right->color == Color::BLACK;
            if (node == root) {
                node->color == Color::BLACK;
            }
        }
    }

    Node<T> *getBrother(const Node<T> *node) const {
        if (node->parent == nullptr) {
            return nullptr;
        }

        if (node->parent->left == node) {
            return node->parent->right;
        } else {
            return node->parent->left;
        }
    }

    Node<T> *getGrandparent(const Node<T> *node) const {
        if (node == nullptr) {
            if (node->parent == nullptr) {
                return nullptr;
            }
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

    void rotateLeft(Node<T> *node) {
        Node<T> *pivot = node->right;
        pivot->parent = node->parent;

        if (pivot->parent != nullptr) {
            if (pivot->parent->left == node) {
                node->parent->left = pivot;
            } else {
                node->parent->right = pivot;
            }
        }

        node->right = pivot->left;
        if (node->right != nullptr) {
            pivot->left->parent = node;
        }

        node->parent = pivot;
        pivot->left = node;
    }

    void rotateRight(Node<T> *node) {
        Node<T> *pivot = node->left;
        pivot->parent = node->parent;

        if (pivot->parent != nullptr) {
            if (pivot->parent->left == node) {
                node->parent->left = pivot;
            } else {
                node->parent->right = pivot;
            }
        }

        node->left = pivot->right;
        if (node->left != nullptr) {
            pivot->right->parent = node;
        }

        node->parent = pivot;
        pivot->right = node;
    }

    void destroy(Node<T> *node) {
        if (root == nullptr) {
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
    RBTree<int> *rb_tree = new RBTree<int>();



    delete rb_tree;

    return 0;
}
