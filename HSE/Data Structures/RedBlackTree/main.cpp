#include <iostream>
#include <string>
#include "CheckRbTree.h"
// enum class Color { RED, BLACK };
//
// template <typename T>
// struct Node {
//     T key;
//     Node *left = nullptr;
//     Node *right = nullptr;
//     Node *parent = nullptr;
//     Color color = Color::RED;
// };

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

    void print(const Node<T> *node) const {
        if (node == nullptr) {
            return;
        }

        std::string color = node->color == Color::RED ? "RED" : "BLACK";

        std::string left_color, right_color;
        if (node->left != nullptr) {
            left_color = node->left->color == Color::RED ? "RED" : "BLACK";
        } else {
            left_color = "null";
        }

        if (node->right != nullptr) {
            right_color = node->right->color == Color::RED ? "RED" : "BLACK";
        } else {
            right_color = "null";
        }

        std::cout << node->key << " color: " << color;

        if (node->left != nullptr) {
            std::cout << " left: " << node->left->key << ";" << left_color << " ; ";
        }

        if (node->right != nullptr) {
            std::cout << " right: " << node->right->key << ";" << right_color;
        }

        std::cout << "\n";

        print(node->left);
        print(node->right);
    }

    ~RBTree() {
        destroy(root);
    }

private:
    int size_ = 0;

    void insert(Node<T> *&root, int key) {
        Node<T> *node = new Node<T>();
        node->key = key;

        //        if (root == nullptr) {
        //            root = node;
        //            node->color = Color::BLACK;
        //            return;
        //        }

        // Find the correct place to insert the new node.
        Node<T> *current = root;
        Node<T> *parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (node->key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Insert the new node.
        node->parent = parent;
        if (node->key < parent->key) {
            parent->left = node;
        } else {
            parent->right = node;
        }

        // Fix any red-black tree violations.
        fixTree(root, node);
    }

    void setColor(Node<T> *node, Color color) {
        if (node != nullptr) {
            node->color = color;
        }
    }

    // Rotates the given subtree to the left.
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

    // Rotates the given subtree to the right.
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

    void fixTree(Node<T> *&root, Node<T> *node) {
        // Case 1: the new node is the root.
        if (node->parent == nullptr) {
            node->color = Color::BLACK;
            return;
        }

        // Case 2: the parent of the new node is black.
        if (node->parent->color == Color::BLACK) {
            return;
        }

        // Case 3: the uncle of the new node is red.
        Node<T> *grandparent = node->parent->parent;
        Node<T> *uncle = nullptr;
        if (grandparent->left == node->parent) {
            uncle = grandparent->right;
        } else {
            uncle = grandparent->left;
        }
        if (uncle != nullptr && uncle->color == Color::RED) {
            node->parent->color = Color::BLACK;
            uncle->color = Color::BLACK;
            grandparent->color = Color::RED;
            fixTree(root, grandparent);
            return;
        }

        // Case 4: the uncle of the new node is black and the new node is a right child.
        if (node->parent->right == node && grandparent->left == node->parent) {
            rotateLeft(node->parent);
            node = node->left;
        }
        // Case 5: the uncle of the new node is black and the new node is a left child.
        else if (node->parent->left == node && grandparent->right == node->parent) {
            rotateRight(node->parent);
            node = node->right;
        }

        // Case 6: the uncle of the new node is black and the new node is a left child.
        if (node->parent->left == node) {
            rotateRight(grandparent);
        }
        // Case 7: the uncle of the new node is black and the new node is a right child.
        else {
            rotateLeft(grandparent);
        }
        node->parent->color = Color::BLACK;
        grandparent->color = Color::RED;
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
    RBTree<int> *rb_tree = new RBTree<int>(/*{2, 0, 3, 1, 4}*/);

    srand(time(nullptr));

    for (int i = 0; i < 10; ++i) {
        int number = Utils::getRandomNumber(0, 1000);
        if (rb_tree->find(number) != nullptr) {
            --i;
            continue;
        }
        rb_tree->insert(number);
    }

    rb_tree->print(rb_tree->root);

    CheckRBTree<int> *checkRbTree = new CheckRBTree<int>();
    if (checkRbTree->isRBTree(rb_tree->root)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    delete rb_tree;

    return 0;
}
