#include "convert-bst-to-greater-tree.hpp"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) { }

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }

TreeNode *ConvertBSTToGreaterTree::convertBST(TreeNode *root) const {
  int max = 0;
  convertBST(root, max);
  return root;
}

void ConvertBSTToGreaterTree::convertBST(TreeNode *root, int &max) const {
  if (root == nullptr) {
    return;
  }

  convertBST(root->right, max);
  max += root->val;
  root->val = max;
  convertBST(root->left, max);
}
