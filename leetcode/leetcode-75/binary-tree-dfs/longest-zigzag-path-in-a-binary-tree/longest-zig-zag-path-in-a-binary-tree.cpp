#include "longest-zig-zag-path-in-a-binary-tree.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

int LongestZigZagPathInABinaryTree::longestZigZag(const TreeNode *root) const {
    int max = 0;
    int count = 0;
    this->maxZigZag(root, LEFT, max, count);
    this->maxZigZag(root, RIGHT, max, count);
    return max;
}

void LongestZigZagPathInABinaryTree::maxZigZag(const TreeNode *root, const Direction direction,
                                               int &max, int count) const {
    if (root == nullptr) {
        return;
    }

    max = std::max(max, count);
    if (direction == LEFT) {
        this->maxZigZag(root->left, RIGHT, max, count + 1);
        this->maxZigZag(root->right, LEFT, max, 1);
    } else {
        this->maxZigZag(root->left, RIGHT, max, 1);
        this->maxZigZag(root->right, LEFT, max, count);
    }
}
