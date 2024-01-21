#include "balanced-binary-tree.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

bool BalancedBinaryTree::isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    int left = depth(root->left);
    int right = depth(root->right);

    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int BalancedBinaryTree::depth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int left = depth(root->left);
    int right = depth(root->right);

    return (left > right ? left : right) + 1;
}