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

        bool balance = true;
        isBalanced(root_, balance);

        return isRb(root_) && balance;
    }

    ~RBTree() {
        destruct(root_);
    }

private:
    Node *root_ = nullptr;

    bool isRb(const Node *root) const {
        bool result;

        if (root == nullptr) {
            return true;
        }

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

        return result;
    }

    int isBalanced(Node *root, bool &result) const {
        if (root == nullptr) {
            return 0;
        }

        int l = isBalanced(root->left, result);
        int r = isBalanced(root->right, result);

        if (l + 1 > 2 * (r + 1)) {
            result = false;
        }

        if (r + 1 > 2 * (l + 1)) {
            result = false;
        }

        return (l > r) ? l + 1 : r + 1;
    }

    bool red(const Node *root) const {
        bool result = false;
        if (root->left != nullptr) {
            result = red(root->left);
        }

        if (root->right != nullptr) {
            result = red(root->right);
        }

        if (root->color == R) {
            if (root->left != nullptr) {
                if (root->color == root->left->color) {
                    return true;
                }
            }

            if (root->right != nullptr) {
                if (root->color == root->right->color) {
                    return true;
                }
            }
        }

        return result;
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

#include <fstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string inp = "../inputs/input_";
    for (int i = 1; i <= 5; ++i) {
        std::string path = inp + std::to_string(i);
        std::ifstream f_in(path);

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

        cout << "\n";
    }

    return 0;
}
