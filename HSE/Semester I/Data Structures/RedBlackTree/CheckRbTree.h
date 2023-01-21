//
// Created by David Natroshvili on 14.12.2022.
//

#ifndef REDBLACKTREE_CHECKRBTREE_H
#define REDBLACKTREE_CHECKRBTREE_H

#include <vector>
#include <iostream>
#include <string>

using std::cin;
using std::cout;

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
class CheckRBTree {
public:
    CheckRBTree() {
    }

    void insert(Node<T> *root) {
        root_ = root;
    }

    bool isRBTree(Node<T> *root) const {
        if (root == nullptr) {
            return true;
        }

        if (root->parent != nullptr) {
            if (root->color == Color::RED && root->parent->color == Color::RED) {
                return false;
            }
        }

        if (root->left != nullptr) {
            if (root->key <= root->left->key) {
                return false;
            }
        }

        if (root->right != nullptr) {
            if (root->key >= root->right->key) {
                return false;
            }
        }

        bool left = isRBTree(root->left);
        bool right = isRBTree(root->right);

        return left && right;
    }

    int balanced(Node<T> *node, bool &balance) const {
        if (node == nullptr) {
            return 1;
        }

        int l = balanced(node->left, balance);
        int r = balanced(node->right, balance);

        if (l != r) {
            balance = false;
        }

        if (node->color == Color::BLACK) {
            return (l > r) ? l + 1 : r + 1;
        }

        return (l > r) ? l : r;
    }

    ~CheckRBTree() {
    }

private:
    Node<T> *root_ = nullptr;
};

#endif  // REDBLACKTREE_CHECKRBTREE_H
