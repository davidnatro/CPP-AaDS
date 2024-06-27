#ifndef LEETCODE_PROBLEMS_MEDIUM_CONVERT_BST_TO_GREATER_TREE_CONVERT_BST_TO_GREATER_TREE_HPP_
#define LEETCODE_PROBLEMS_MEDIUM_CONVERT_BST_TO_GREATER_TREE_CONVERT_BST_TO_GREATER_TREE_HPP_

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

class ConvertBSTToGreaterTree {
 public:
  TreeNode *convertBST(TreeNode *root) const;

 private:
  void convertBST(TreeNode *root, int &max) const;
};

#endif
