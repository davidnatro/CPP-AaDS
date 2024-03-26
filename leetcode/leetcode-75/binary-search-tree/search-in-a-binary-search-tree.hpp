#ifndef LEETCODE_LEETCODE_75_BINARY_SEARCH_TREE_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP_
#define LEETCODE_LEETCODE_75_BINARY_SEARCH_TREE_SEARCH_IN_A_BINARY_SEARCH_TREE_HPP_

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

class SearchInABinarySearchTree {
 public:
  TreeNode *searchBST(TreeNode *root, int val) const;
};

#endif
