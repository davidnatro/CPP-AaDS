#include "search-in-a-binary-search-tree.hpp"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

TreeNode *SearchInABinarySearchTree::searchBST(TreeNode *root, int val) const {
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == val) {
    return root;
  }

  if (val < root->val) {
    return searchBST(root->left, val);
  }

  return searchBST(root->right, val);
}
