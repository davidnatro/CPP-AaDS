#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_BFS_MAXIMUM_LEVEL_SUM_OF_A_BINARY_TREE_MAXIMUM_LEVEL_SUM_OF_A_BINARY_TREE_HPP_
#define LEETCODE_LEETCODE_75_BINARY_TREE_BFS_MAXIMUM_LEVEL_SUM_OF_A_BINARY_TREE_MAXIMUM_LEVEL_SUM_OF_A_BINARY_TREE_HPP_

// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

class MaximumLevelSumOfABinaryTree {
 public:
  int maxLevelSum(TreeNode *root) const;
};

#endif
