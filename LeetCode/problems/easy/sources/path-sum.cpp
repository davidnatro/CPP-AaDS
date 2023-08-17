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

bool PathSum::hasPathSum(TreeNode *root, int target_sum) {
    if (root == nullptr) {
        return false;
    }

    target_sum -= root->val;
    bool left = false;
    bool right = false;

    if (target_sum == 0) {
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
    }

    if (root->left != nullptr) {
        left = hasPathSum(root->left, target_sum);
    }

    if (root->right != nullptr) {
        right = hasPathSum(root->right, target_sum);
    }

    return left || right;
}