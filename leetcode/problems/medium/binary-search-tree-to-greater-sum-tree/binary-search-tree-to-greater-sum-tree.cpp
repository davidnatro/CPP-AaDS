#include "binary-search-tree-to-greater-sum-tree.hpp"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) { }

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }

TreeNode *BinarySearchTreeToGreaterSumTree::bstToGst(TreeNode *root) const {
  int max = 0;
  bstToGst(root, max);
  return root;
}

void BinarySearchTreeToGreaterSumTree::bstToGst(TreeNode *root, int &max) const {
  if (root == nullptr) {
    return;
  }

  bstToGst(root->right, max);
  max += root->val;
  root->val = max;
  bstToGst(root->left, max);
}
