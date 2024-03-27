#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_DFS_MAXIMUM_DEPTH_OF_BINARY_TREE_MAXIMUM_DEPTH_OF_BINARY_TREE_H_
#define LEETCODE_LEETCODE_75_BINARY_TREE_DFS_MAXIMUM_DEPTH_OF_BINARY_TREE_MAXIMUM_DEPTH_OF_BINARY_TREE_H_

// https://leetcode.com/problems/maximum-depth-of-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

class MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode *root) const;
};

#endif
