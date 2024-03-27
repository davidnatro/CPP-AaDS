#include "maximum-level-sum-of-a-binary-tree.hpp"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

int MaximumLevelSumOfABinaryTree::maxLevelSum(TreeNode *root) const {
  if (root == nullptr) {
    return 0;
  }

  int level = 0;
  int current_level = 0;
  int max = INT32_MIN;
  std::queue<TreeNode *> nodes;
  nodes.push(root);
  while (!nodes.empty()) {
    current_level += 1;
    int size = nodes.size();
    int sum = 0;
    while (size > 0) {
      TreeNode *node = nodes.front();
      nodes.pop();

      sum += node->val;

      if (node->left != nullptr) {
        nodes.push(node->left);
      }

      if (node->right != nullptr) {
        nodes.push(node->right);
      }

      size -= 1;
    }

    if (sum > max) {
      max = sum;
      level = current_level;
    }
  }

  return level;
}
