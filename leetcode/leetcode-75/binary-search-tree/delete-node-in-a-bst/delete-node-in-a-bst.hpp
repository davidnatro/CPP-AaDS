#ifndef LEETCODE_LEETCODE_75_BINARY_SEARCH_TREE_DELETE_NODE_IN_A_BST_DELETE_NODE_IN_A_BST_HPP_
#define LEETCODE_LEETCODE_75_BINARY_SEARCH_TREE_DELETE_NODE_IN_A_BST_DELETE_NODE_IN_A_BST_HPP_

// https://leetcode.com/problems/delete-node-in-a-bst/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

class DeleteNodeInABST {
 public:
  TreeNode *deleteNode(TreeNode *root, const int key) const;
};

#endif
