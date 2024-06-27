#ifndef LEETCODE_PROBLEMS_MEDIUM_BINARY_SEARCH_TREE_TO_GREATER_SUM_TREE_BINARY_SEARCH_TREE_TO_GREATER_SUM_TREE_HPP_
#define LEETCODE_PROBLEMS_MEDIUM_BINARY_SEARCH_TREE_TO_GREATER_SUM_TREE_BINARY_SEARCH_TREE_TO_GREATER_SUM_TREE_HPP_

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

class BinarySearchTreeToGreaterSumTree {
 public:
  TreeNode *bstToGst(TreeNode *root) const;

 private:
  void bstToGst(TreeNode *root, int &max) const;
};

#endif
