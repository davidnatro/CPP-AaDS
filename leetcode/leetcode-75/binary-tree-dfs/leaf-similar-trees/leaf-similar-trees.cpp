#include "leaf-similar-trees.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

bool LeafSimilarTrees::leafSimilar(TreeNode *root1, TreeNode *root2) const {
    std::vector<int> left;
    std::vector<int> right;

    traverse(root1, left);
    traverse(root2, right);

    return left == right;
}

void LeafSimilarTrees::traverse(TreeNode *node, std::vector<int> &leaves) const {
    if (node == nullptr) {
        return;
    }

    traverse(node->left, leaves);
    if (node->left == nullptr && node->right == nullptr) {
        leaves.emplace_back(node->val);
    }
    traverse(node->right, leaves);
}
