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
    }

private:
    Node *root_ = nullptr;

    bool isRb(Node *root) const {
        if (root->left != nullptr) {
            if ((root->color == R && root->left->color == R) || root->key < root->left->key) {
                return false;
            }

            return isRb(root->left);
        }

        if (root->right != nullptr) {
            if ((root->color == R && root->right->color == R) || root->key > root->right->key) {
                return false;
            }

            return isRb(root->right);
        }

        bool balanced = true;
        isBalanced(root, &balanced);

        return balanced;
    }

    int isBalanced(Node *root, bool *balance) const {
        if (root == nullptr) {
            return 0;
        }

        int l = isBalanced(root->left, balance);
        int r = isBalanced(root->right, balance);

        if ((l + 1) > 2 * (r + 1)) {
            *balance = false;
        }

        if ((r + 1) > 2 * (l + 1)) {
            *balance = false;
        }

        return (l > r) ? l + 1 : r + 1;
    }

    int getMaxHeight(const Node *node) const {
        if (node == nullptr) {
            return 0;
        }

        int height_l = 0;
        int height_r = 0;

        if (node->left != nullptr) {
            height_l = getMaxHeight(node->left);
        }

        if (node->right != nullptr) {
            height_r = getMaxHeight(node->right);
        }
        return (height_r > height_l) ? height_r + 1 : height_l + 1;
    }

    int getMinHeight(const Node *node) const {
        if (node == nullptr) {
            return 0;
        }

        if (node->right == nullptr && node->left == nullptr) {
            return 0;
        }

        int height_l = INT32_MAX;
        int height_r = INT32_MAX;

        if (node->left != nullptr) {
            height_l = getMinHeight(node->left);
        }

        if (node->right != nullptr) {
            height_r = getMinHeight(node->right);
        }
        return (height_r < height_l) ? height_r + 1 : height_l + 1;
    }
};

#include <fstream>                        // delete
std::ifstream f_in("../inputs/input_4");  // delete

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
    uint16_t rootIndex;
    cin >> rootIndex;

    std::vector<Node *> nodes(size);

    RBTree *tree = new RBTree();

    std::string input;
    for (int i = 0; i < size; ++i) {
        Node *node = new Node();
        nodes[i] = node;

        cin >> node->number;
        cin >> node->key;

        cin >> input;
        if (input == "null") {
            node->left = nullptr;
        } else {
            node->left = new Node();
            nodes[++i] = node->left;
            node->left->number = std::stoi(input);
        }

        cin >> input;
        if (input == "null") {
            node->right = nullptr;
        } else {
            node->right = new Node();
            nodes[++i] = node->right;
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
        if (nodes[i]->number == rootIndex) {
            root_node = nodes[i];
            break ;
        }
    }

    root_node = build(root_node, nodes);

    tree->insert(root_node);
    if (tree->isRBTree()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    for (int i = 0; i < size; ++i) {
        delete nodes[i];
    }

    delete tree;

    return 0;
}
