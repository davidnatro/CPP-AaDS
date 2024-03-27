#include "lowest-common-ancestor-of-a-binary-tree.hpp"

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode *LowestCommonAncestorOfABinaryTree::lowestCommonAncestor(TreeNode *root,
                                                                  TreeNode *p,
                                                                  TreeNode *q) const {
  if (root == nullptr || root == p || root == q) {
    return root;
  }

  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left != nullptr && right != nullptr) {
    return root;
  }

  return left ? left : right;
}