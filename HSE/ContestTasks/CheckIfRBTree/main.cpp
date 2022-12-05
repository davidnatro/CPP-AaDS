#include <vector>
#include <iostream>
#include <string>

using std::cin;
using std::cout;

enum Color { R, B };

struct Node {
    int key;
    int number = 0;

    Node *left = nullptr;
    Node *right = nullptr;
    Color color = R;
};

Node *findNode(const std::vector<Node *> &nodes, const int number) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i]->number == number) {
            return nodes[i];
        }
    }
    return nullptr;
}

class RBTree {
public:
    RBTree() {
    }

    bool isRBTree(Node *root) const {
        if (root == nullptr) {
            return true;
        }

        bool left = isRBTree(root->left);
        bool right = isRBTree(root->right);

        if (root->left != nullptr && root->right != nullptr) {
            if (root->left->color == B && root->right->color == B && root->color == R) {
                root->color = B;
                root->left->color = R;
                root->right->color = R;
            }
        }

        if (root->left != nullptr) {
            if (root->key <= root->left->key) {
                return false;
            }
            if (root->color == R && root->left->color == R) {
                return false;
            }

            if (root->left->left == nullptr || root->left->right == nullptr) {
                if (root->color == R) {
                    return false;
                }
            }
        }

        if (root->right != nullptr) {
            if (root->key >= root->right->key) {
                return false;
            }

            if (root->color == R && root->right->color == R) {
                return false;
            }

            if (root->right->left == nullptr || root->right->right == nullptr) {
                if (root->color == R) {
                    return false;
                }
            }
        }

        bool balance = true;
        isBalanced(root, balance);

        return left && right && balance;
    }

    ~RBTree() {
    }

private:
    Node *root_ = nullptr;

    int isBalanced(const Node *root, bool &result) const {
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
};

#include <fstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //    std::string inp = "../inputs/input_";
    //    for (int j = 1; j <= 5; ++j) {
    //        std::string path = inp + std::to_string(j);
    //        std::ifstream f_in(path);
    //
    //        cin.rdbuf(f_in.rdbuf());  // delete

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

    std::vector<Node *> nodes;

    RBTree *tree = new RBTree();
    Node *root = nullptr;

    std::string input;
    for (int i = 0; i < size; ++i) {
        Node *node;

        int number, key;

        cin >> number;
        cin >> key;

        if (number == root_index) {
            node = new Node();
            node->number = number;
            root = node;
        } else {
            node = findNode(nodes, number);
            if (node == nullptr) {
                node = new Node();
                node->number = number;
                nodes.emplace_back(node);
            }
        }

        node->key = key;

        cin >> input;
        if (input == "null") {
            node->left = nullptr;
        } else {
            int node_number = std::stoi(input);
            node->left = findNode(nodes, node_number);
            if (node->left == nullptr) {
                node->left = new Node();
                node->left->number = std::stoi(input);
                nodes.emplace_back(node->left);
            }
        }

        cin >> input;
        if (input == "null") {
            node->right = nullptr;
        } else {
            int node_number = std::stoi(input);
            node->right = findNode(nodes, node_number);
            if (node->right == nullptr) {
                node->right = new Node();
                node->right->number = std::stoi(input);
                nodes.emplace_back(node->right);
            }
        }

        cin >> input;
        if (input == "R") {
            node->color = R;
        } else {
            node->color = B;
        }

        cout.flush();
    }

    if (root == nullptr) {
        cout << "YES";
        // ?
        for (int i = 0; i < nodes.size(); ++i) {
            delete nodes[i];
        }
        delete root;
        delete tree;
        return 0;
    }

    if (root->color == R) {
        cout << "NO";
        for (int i = 0; i < nodes.size(); ++i) {
            delete nodes[i];
        }
        delete root;
        delete tree;
        return 0;
    }

    if (tree->isRBTree(root)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    for (int i = 0; i < nodes.size(); ++i) {
        delete nodes[i];
    }
    delete root;
    delete tree;

    //        cout << "\n";
    //    }

    return 0;
}