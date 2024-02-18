#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_DFS_COUNT_GOOD_NODES_IN_BINARY_TREE_COUNT_GOOD_NODES_IN_BINARY_TREE_H_
#define LEETCODE_LEETCODE_75_BINARY_TREE_DFS_COUNT_GOOD_NODES_IN_BINARY_TREE_COUNT_GOOD_NODES_IN_BINARY_TREE_H_

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

class CountGoodNodesInBinaryTree {
public:
    int goodNodes(TreeNode *root) const;
};

#endif
