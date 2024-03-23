#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_DFS_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_HPP_
#define LEETCODE_LEETCODE_75_BINARY_TREE_DFS_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_TREE_HPP_

#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x);
};

class LowestCommonAncestorOfABinaryTree {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) const;
};

#endif
