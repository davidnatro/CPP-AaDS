#include <vector>

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
        if (root_->color == R) {
            return false;
        }

        if (root_->color == R && (root_->left->color == R || root_->right->color == R)) {
            return false;
        }
    }

    ~RBTree() {
        destruct(root_);
    }

private:
    Node *root_ = nullptr;

    void destruct(Node *node) {
        if (node->left != nullptr) {
            node = node->left;
        }

        if (node->right != nullptr) {
            node = node->right;
        }

        delete node;
    }

    int getHeight(const Node *node) const {
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
};

#include <iostream>

// #include <fstream>

using std::cin;
using std::cout;

Node *build(Node *root, const std::vector<Node *> &nodes) {
    if (root->left != nullptr) {
        root->left = nodes[root->left->number - 1];
        root->left = build(root->left, nodes);
    }

    if (root->right != nullptr) {
        root->right = nodes[root->right->number - 1];
        root->right = build(root->right, nodes);
    }

    return root;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Размер дерева.
    uint16_t size;
    cin >> size;

    // NO, если размер == 0.
    if (size == 0) {
        cout << "NO";
        return 0;
    }

    // Номер корневой вершины.
    uint16_t root;
    cin >> root;

    std::vector<Node *> nodes;

    RBTree *tree = new RBTree();

    std::string input;
    for (int i = 0; i < size; ++i) {
        Node *node = new Node();

        cin >> node->number;
        cin >> node->key;

        cin >> input;
        if (input == "null") {
            node->left = nullptr;
        } else {
            node->left = new Node();
            node->left->number = std::stoi(input);
        }

        cin >> input;
        if (input == "null") {
            node->right = nullptr;
        } else {
            node->right = new Node();
            node->right->number = std::stoi(input);
        }

        cin >> input;
        if (input == "R") {
            node->color = R;
        } else {
            node->color = B;
        }

        nodes.emplace_back(node);
    }

    Node *root_node = nodes[root - 1];
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
