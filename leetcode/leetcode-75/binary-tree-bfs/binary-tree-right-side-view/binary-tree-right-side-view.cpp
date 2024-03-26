#include "binary-tree-right-side-view.hpp"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

std::vector<int> BinaryTreeRightSideView::rightSideView(TreeNode *root) const {
  std::vector<int> data;

  if (root == nullptr) {
    return data;
  }

  std::queue<TreeNode *> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    int size = nodes.size();
    TreeNode *node;
    while (size > 0) {
      node = nodes.front();
      if (node->left != nullptr) {
        nodes.push(node->left);
      }
      if (node->right != nullptr) {
        nodes.push(node->right);
      }
      nodes.pop();
      size -= 1;
    }
    data.emplace_back(node->val);
  }

  return data;
}
