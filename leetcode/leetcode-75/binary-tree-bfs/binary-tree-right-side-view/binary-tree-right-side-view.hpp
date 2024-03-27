#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_BFS_BINARY_TREE_RIGHT_SIDE_VIEW_HPP_
#define LEETCODE_LEETCODE_75_BINARY_TREE_BFS_BINARY_TREE_RIGHT_SIDE_VIEW_HPP_

// https://leetcode.com/problems/binary-tree-right-side-view/

#include <vector>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);
};

class BinaryTreeRightSideView {
 public:
  std::vector<int> rightSideView(TreeNode *root) const;
};

#endif
