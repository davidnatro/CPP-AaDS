#include <iostream>

enum Color { RED, BLACK };

template <typename T>
struct Node {
    T value;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
    Node<T> *parent = nullptr;
    Color color = RED;

    Node() {
    }

    explicit Node(const T &x) {
        value = x;
    }
};

template <typename ValueType>
class RBTree {
public:
    struct Iterator {
        Iterator() {
            root = nullptr;
        }

        explicit Iterator(Node<ValueType> *node) {
            root = node;
        }

        const ValueType &operator*() const {
            return root->value;
        }

        const ValueType *operator->() const {
            return root->value;
        }

        Iterator &operator++() {
            return nullptr;
        }

        Iterator operator++(int) {
            return nullptr;
        }

        Iterator &operator--() {
            return nullptr;
        }

        Iterator operator--(int) {
            return nullptr;
        }

        bool operator==(const Iterator &other) const {
            return root->value == other.root->value;
        }

        bool operator!=(const Iterator &other) const {
            return !(*this == other);
        }

    private:
        Node<ValueType> *root{};
    };

public:
    Node<ValueType> *root;

    RBTree() {
        root = nullptr;
    }

    RBTree(std::initializer_list<ValueType> list) {
        size_ = list.size();

        for (const ValueType *it = list.begin(); it != list.end(); ++it) {
            insert(*it);
        }
    }

    RBTree(const RBTree &other) {
        size_ = other.size_;
        root = this->copyTree(other.root);
    }

    RBTree<ValueType> &operator=(const RBTree &other) {
        if (this == &other) {
            return *this;
        }

        destroy(root);

        this->root = other.root;
        size_ = other.size_;

        return *this;
    }

    void insert(const ValueType &value) {
        if (root == nullptr) {
            root = new Node<ValueType>();
            root->value = value;
            root->color = Color::BLACK;
            size_ += 1;
            return;
        }

        insert(root, value);
        size_ += 1;
    }

    void erase(const ValueType &value) {
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return root == nullptr;
    }

    Iterator lowerBound(const ValueType &value) const {
        return nullptr;
    }

    Iterator find(const ValueType &value) const {
        return nullptr;
    }

    Iterator begin() const {
        return Iterator(root);
    }

    Iterator end() const {
        return nullptr;
    }

    ~RBTree() {
        destroy(root);
    }

private:
    int size_ = 0;
    ValueType *array_ = nullptr;
    int index = -1;

    void insert(Node<ValueType> *&root, ValueType value) {
        Node<ValueType> *node = new Node<ValueType>();
        node->value = value;

        Node<ValueType> *current = root;
        Node<ValueType> *parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (node->value < current->value) {
                current = current->left;
            } else if (current->value < node->value) {
                current = current->right;
            } else {
                delete node;
                size_ -= 1;
                return;
            }
        }

        node->parent = parent;
        if (node->value < parent->value) {
            parent->left = node;
        } else {
            parent->right = node;
        }

        balance(root, node);
    }

    void setColor(Node<ValueType> *node, Color color) {
        if (node != nullptr) {
            node->color = color;
        }
    }

    void rotateLeft(Node<ValueType> *&root, Node<ValueType> *node) {
        Node<ValueType> *right = node->right;
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

    void rotateRight(Node<ValueType> *&root, Node<ValueType> *node) {
        Node<ValueType> *left = node->left;
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

    void balance(Node<ValueType> *&root, Node<ValueType> *node) {
        if (node->parent == nullptr) {
            node->color = Color::BLACK;
            return;
        }

        if (node->parent->color == Color::BLACK) {
            return;
        }

        Node<ValueType> *grandparent = getGrandparent(node);
        Node<ValueType> *uncle = getUncle(node);

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

    void recolor(Node<ValueType> *node) {
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

    Node<ValueType> *getGrandparent(const Node<ValueType> *node) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->parent == nullptr) {
            return nullptr;
        }

        return node->parent->parent;
    }

    Node<ValueType> *getUncle(const Node<ValueType> *node) const {
        Node<ValueType> *grandparent = getGrandparent(node);
        if (grandparent == nullptr) {
            return nullptr;
        }

        return (node->parent == grandparent->left) ? grandparent->right : grandparent->left;
    }

    Node<ValueType> *copyTree(const Node<ValueType> *other) const {
        if (other == nullptr) {
            return nullptr;
        }

        Node<ValueType> *new_node = new Node<ValueType>();
        new_node->value = other->value;
        new_node->color = other->color;

        new_node->left = copyTree(other->left);
        new_node->right = copyTree(other->right);

        return new_node;
    }

    void getArray(const Node<ValueType> *node) {
        if (node == nullptr) {
            return;
        }

        getArray(node->left);

        array_[++index] = node->value;

        getArray(node->right);
    }

    void destroy(Node<ValueType> *node) {
        if (node == nullptr) {
            return;
        }

        destroy(node->left);
        destroy(node->right);

        delete node;
    }
};

#include "Utils.h"

using std::cout;

int main() {
    RBTree<int> *tree = new RBTree<int>();
    srand(time(nullptr));

    for (int i = 0; i < 100; ++i) {
        int number = Utils::getRandomNumber(0, 1000);
        tree->insert(number);
    }

    RBTree<int> *new_tree = new RBTree<int>(*tree);
    cout << (tree->root->value) << "\n";
    cout << new_tree->root->value << "\n";
    cout << std::boolalpha << (tree->root->value == new_tree->root->value) << "\n";
    cout << std::boolalpha << (tree->size() == new_tree->size()) << "\n";

    cout << *tree->begin() << "\n";

    cout << std::boolalpha << (tree->begin() != new_tree->begin()) << "\n";

    delete tree;
}
