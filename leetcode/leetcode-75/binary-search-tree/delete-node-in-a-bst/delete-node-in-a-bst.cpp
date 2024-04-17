#include "delete-node-in-a-bst.hpp"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

TreeNode *DeleteNodeInABST::deleteNode(TreeNode *root, const int key) const {
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val < key) {
    root->right = deleteNode(root->right, key);
  } else if (root->val > key) {
    root->left = deleteNode(root->left, key);
  } else {
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }

    if (root->left == nullptr || root->right == nullptr) {
      TreeNode *result = (root->left == nullptr) ? root->right : root->left;
      return result;
    }

    TreeNode *result = root->left;
    while (result->right != nullptr) {
      result = result->right;
    }
    root->val = result->val;
    root->left = deleteNode(root->left, result->val);
  }

  return root;
}
