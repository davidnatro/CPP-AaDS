#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_BALANCED_BINARY_TREE_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_BALANCED_BINARY_TREE_H_

// https://leetcode.com/problems/balanced-binary-tree/

#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

class BalancedBinaryTree {
public:
    bool isBalanced(TreeNode *root);

private:
    int depth(TreeNode *root);
};

#endif
