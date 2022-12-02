#include <vector>
#include <iostream>
#include <string>

enum Color { R, B };

struct Node {
    int key;
    int number = 0;

    Node *left = nullptr;
    Node *right = nullptr;
    Color color = B;
};

class RBTree {
public:
    RBTree() {
    }

    void insert(Node *node) {
        root_ = node;
    }

    bool isRBTree() const {
        if (root_ == nullptr) {
            return true;
        }

        if (root_->color == R) {
            return false;
        }

        return isRb(root_);
    }

    ~RBTree() {
        destruct(root_);
    }

private:
    Node *root_ = nullptr;

    bool isRb(Node *root) const {
        bool result = true;

        if (root->left != nullptr) {
            if (root->key < root->left->key) {
                return false;
            }

            result = isRb(root->left);
        }

        if (root->right != nullptr) {
            if (root->key > root->right->key) {
                return false;
            }

            result = isRb(root->right);
        }

        if (redSeries(root)) {
            return false;
        }

        int minh, maxh;
        if (!isBalanced(root, maxh, minh)) {
            return false;
        }

        return result;
    }

    bool isBalanced(Node *root, int &maxh, int &minh) const {
        if (root == nullptr) {
            maxh = minh = 0;
            return true;
        }

        int lmxh, lmnh;  // To store max and min heights of left subtree
        int rmxh, rmnh;  // To store max and min heights of right subtree

        // Check if left subtree is balanced, also set lmxh and lmnh
        if (!isBalanced(root->left, lmxh, lmnh)) {
            return false;
        }

        // Check if right subtree is balanced, also set rmxh and rmnh
        if (!isBalanced(root->right, rmxh, rmnh)) {
            return false;
        }

        // Set the max and min heights of this node for the parent call
        maxh = (lmxh > rmxh) ? lmxh + 1 : rmxh + 1;
        minh = (lmnh < rmnh) ? lmnh + 1 : rmnh + 1;

        // See if this node is balanced
        if (maxh <= 2 * minh) {
            return true;
        }

        return false;
    }

    bool redSeries(const Node *node) const {
        if (node == nullptr) {
            return false;
        }

        if (node->color == R) {
            if (node->left != nullptr) {
                if (node->color == node->left->color) {
                    return true;
                }
            }

            if (node->right != nullptr) {
                if (node->color == node->right->color) {
                    return true;
                }
            }
        }

        return false;
    }

    void destruct(Node *root) {
        if (root->left != nullptr) {
            destruct(root->left);
        }

        if (root->right != nullptr) {
            destruct(root->right);
        }

        delete root;
    }
};

#include <fstream>
std::ifstream f_in("../inputs/input_3");

using std::cin;
using std::cout;

Node *findNode(const std::vector<Node *> nodes, int number) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i]->number == number) {
            return nodes[i];
        }
    }
    return nullptr;
}

Node *build(Node *root, const std::vector<Node *> &nodes) {
    if (root->left != nullptr) {
        root->left = findNode(nodes, root->left->number);
        root->left = build(root->left, nodes);
    }

    if (root->right != nullptr) {
        root->right = findNode(nodes, root->right->number);
        root->right = build(root->right, nodes);
    }

    return root;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin.rdbuf(f_in.rdbuf());  // delete

    // Размер дерева.
    uint16_t size;
    cin >> size;

    // NO, если размер == 0.
    if (size == 0) {
        cout << "NO";
        return 0;
    }

    // Номер корневой вершины.
    uint16_t root_index;
    cin >> root_index;

    std::vector<Node *> nodes;

    RBTree *tree = new RBTree();

    std::string input;
    for (int i = 0; i < size; ++i) {
        int number, key;

        cin >> number;
        cin >> key;

        Node *node = findNode(nodes, number);
        if (node == nullptr) {
            node = new Node();
            node->number = number;
        }

        node->key = key;
        nodes.emplace_back(node);

        cin >> input;
        if (input == "null") {
            node->left = nullptr;
        } else {
            node->left = new Node();
            nodes.emplace_back(node->left);
            node->left->number = std::stoi(input);
        }

        cin >> input;
        if (input == "null") {
            node->right = nullptr;
        } else {
            node->right = new Node();
            nodes.emplace_back(node->right);
            node->right->number = std::stoi(input);
        }

        cin >> input;
        if (input == "R") {
            node->color = R;
        } else {
            node->color = B;
        }
    }

    Node *root_node;
    for (int i = 0; i < size; ++i) {
        if (nodes[i]->number == root_index) {
            root_node = nodes[i];
            break;
        }
    }

    root_node = build(root_node, nodes);

    tree->insert(root_node);
    if (tree->isRBTree()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    delete tree;

    return 0;
}
