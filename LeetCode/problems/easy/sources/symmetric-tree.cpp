#include "../headers/symmetric-tree.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

bool SymmetricTree::isSymmetric(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    return isMirror(root, root);
}

bool SymmetricTree::isMirror(TreeNode *leftTree, TreeNode *rightTree) {
    if (leftTree == nullptr && rightTree == nullptr) {
        return true;
    }

    if (leftTree != nullptr && rightTree != nullptr) {
        if (leftTree->val != rightTree->val) {
            return false;
        }

        bool left = isMirror(leftTree->left, rightTree->right);
        bool right = isMirror(leftTree->right, rightTree->left);

        return left && right;
    }

    return false;
}