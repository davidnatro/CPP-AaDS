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

Node *findNode(const std::vector<Node *> nodes, int number) {
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

    void insert(Node *root) {
        root_ = root;
    }

    bool isRBTree(Node *root, const std::vector<Node *> &nodes) const {
        if (root == nullptr) {
            return true;
        }

        if (root->left != nullptr) {
            root->left = findNode(nodes, root->left->number);
            if (root->key <= root->left->key) {
                return false;
            }
        }

        if (root->right != nullptr) {
            root->right = findNode(nodes, root->right->number);
            if (root->key >= root->right->key) {
                return false;
            }
        }

        bool left = isRBTree(root->left, nodes);
        bool right = isRBTree(root->right, nodes);

        if (root->left != nullptr && root->right != nullptr) {
            if (root->left->color == B && root->right->color == B && root->color == R) {
                root->color = B;
                root->left->color = R;
                root->right->color = R;
            }
        }

        if (root->left != nullptr) {
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
            if (root->color == R && root->right->color == R) {
                return false;
            }

            if (root->right->left == nullptr || root->right->right == nullptr) {
                if (root->color == R) {
                    return false;
                }
            }
        }

        //        if (red(root)) {
        //            return false;
        //        }

        bool balance = true;
        isBalanced(root, balance);

        return left && right && balance;
    }

    ~RBTree() {
        // destruct(root_);
    }

private:
    Node *root_ = nullptr;

    bool isRb(Node *root) {
        if (root == nullptr) {
            return true;
        }

        bool left = isRb(root->left);

        bool right = isRb(root->right);

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

            if (root->left->left == nullptr && root->left->right == nullptr) {
                if (root->color == R) {
                    return false;
                }
            }
        }

        if (root->right != nullptr) {
            if (root->key >= root->right->key) {
                return false;
            }

            if (root->right->left == nullptr && root->right->right == nullptr) {
                if (root->color == R) {
                    return false;
                }
            }
        }

        return left && right;
    }

    bool red(const Node *root) const {
        if (root == nullptr) {
            return false;
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

        bool left = red(root->left);
        bool right = red(root->right);

        return left || right;
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

    void destruct(Node *root) {
        if (root_ == nullptr) {
            return;
        }

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

    std::string input;
    for (int i = 0; i < size; ++i) {
        int number, key;

        cin >> number;
        cin >> key;

        Node *node = findNode(nodes, number);
        if (node == nullptr) {
            node = new Node();
            node->number = number;
            nodes.emplace_back(node);
        }

        node->key = key;

        cin >> input;
        if (input == "null") {
            node->left = nullptr;
        } else {
            node->left = new Node();
            node->left->number = std::stoi(input);
            nodes.emplace_back(node->left);
        }

        cin >> input;
        if (input == "null") {
            node->right = nullptr;
        } else {
            node->right = new Node();
            node->right->number = std::stoi(input);
            nodes.emplace_back(node->right);
        }

        cin >> input;
        if (input == "R") {
            node->color = R;
        } else {
            node->color = B;
        }
    }

    Node *root_node = findNode(nodes, root_index);

    if (root_node == nullptr) {
        cout << "YES";
        delete tree;
        return 0;
    }

    if (root_node->color == R) {
        cout << "NO";
        for (int i = 0; i < nodes.size(); ++i) {
            delete nodes[i];
        }
        delete tree;

        return 0;
    }

    tree->insert(root_node);

    if (tree->isRBTree(root_node, nodes)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    for (int i = 0; i < nodes.size(); ++i) {
        delete nodes[i];
    }
    delete tree;

    //        cout << "\n";
    //    }

    return 0;
}