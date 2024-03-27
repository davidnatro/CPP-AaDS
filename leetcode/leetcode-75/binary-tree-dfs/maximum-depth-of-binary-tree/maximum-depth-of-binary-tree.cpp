#include "maximum-depth-of-binary-tree.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

int MaximumDepthOfBinaryTree::maxDepth(TreeNode *root) const {
    if (root == nullptr) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return ((left > right) ? left : right) + 1;
}
