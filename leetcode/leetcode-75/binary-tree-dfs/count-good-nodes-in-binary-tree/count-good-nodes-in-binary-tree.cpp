#include "count-good-nodes-in-binary-tree.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

int CountGoodNodesInBinaryTree::goodNodes(TreeNode *root) const {
    if (root == nullptr) {
        return 0;
    }

    int max = root->val;
    int count = 0;
    this->dfs(root, max, count);
    return count;
}

void CountGoodNodesInBinaryTree::dfs(TreeNode *root, int max, int &count) const {
    if (root == nullptr) {
        return;
    }

    if (root->val >= max) {
        count += 1;
        max = root->val;
    }

    this->dfs(root->left, max, count);
    this->dfs(root->right, max, count);
}
