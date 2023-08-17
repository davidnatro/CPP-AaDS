#include "../headers/path-sum.h"

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

bool PathSum::hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }

    targetSum -= root->val;
    bool left = false;
    bool right = false;

    if (targetSum == 0) {
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
    }

    if (root->left != nullptr) {
        left = hasPathSum(root->left, targetSum);
    }

    if (root->right != nullptr) {
        right = hasPathSum(root->right, targetSum);
    }

    return left || right;
}