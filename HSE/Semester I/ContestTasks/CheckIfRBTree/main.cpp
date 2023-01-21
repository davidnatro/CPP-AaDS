#include <vector>
#include <iostream>
#include <string>

using std::cin;
using std::cout;

enum Color { R, B };

struct Node {
    int key;

    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
    Color color = R;
};

class RBTree {
public:
    RBTree() {
    }

    void insert(Node *root) {
        root_ = root;
    }

    bool isRBTree(Node *root) const {
        if (root == nullptr) {
            return true;
        }

        if (root->parent != nullptr) {
            if (root->color == R && root->parent->color == R) {
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

    int balanced(Node *node, bool &balance) const {
        if (node == nullptr) {
            return 1;
        }

        int l = balanced(node->left, balance);
        int r = balanced(node->right, balance);

        if (l != r) {
            balance = false;
        }

        if (node->color == B) {
            return (l > r) ? l + 1 : r + 1;
        }

        return (l > r) ? l : r;
    }

    ~RBTree() {
    }

private:
    Node *root_ = nullptr;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Размер дерева.
    int size;
    cin >> size;

    // NO, если размер == 0.
    if (size == 0) {
        cout << "NO";
        return 0;
    }

    // Номер корневой вершины.
    int root_index;
    cin >> root_index;

    std::vector<Node *> nodes(size, nullptr);

    RBTree *tree = new RBTree();

    std::string input;
    for (int i = 0; i < size; ++i) {
        int number, key;
        cin >> number;
        cin >> key;
        Node *node;

        if (nodes[number - 1] == nullptr) {
            node = new Node();
            nodes[number - 1] = node;
        } else {
            node = nodes[number - 1];
        }

        node->key = key;

        cin >> input;
        if (input == "null") {
            node->left = nullptr;
        } else {
            int node_number = std::stoi(input);
            node->left = nodes[node_number - 1];
            if (node->left == nullptr) {
                node->left = new Node();
                node->left->parent = node;
                nodes[node_number - 1] = node->left;
            }
        }

        cin >> input;
        if (input == "null") {
            node->right = nullptr;
        } else {
            int node_number = std::stoi(input);
            node->right = nodes[node_number - 1];
            if (node->right == nullptr) {
                node->right = new Node();
                node->right->parent = node;
                nodes[node_number - 1] = node->right;
            }
        }

        cin >> input;
        if (input == "R") {
            node->color = R;
        } else if (input == "B") {
            node->color = B;
        } else {
            cout << "NO";
            for (int j = 0; j < size; ++j) {
                delete nodes[j];
            }
            delete tree;
            return 0;
        }

        cout.flush();
    }

    Node *root = nodes[root_index - 1];

    if (root->color == R) {
        cout << "NO";
        for (int i = 0; i < size; ++i) {
            delete nodes[i];
        }
        delete tree;
        return 0;
    }

    bool balance = true;
    tree->balanced(root, balance);

    tree->insert(root);
    if (tree->isRBTree(root) && balance) {
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