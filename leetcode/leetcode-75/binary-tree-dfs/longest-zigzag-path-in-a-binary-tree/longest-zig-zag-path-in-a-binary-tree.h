#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_DFS_LONGEST_ZIGZAG_PATH_IN_A_BINARY_TREE_LONGEST_ZIG_ZAG_PATH_IN_A_BINARY_TREE_H_
#define LEETCODE_LEETCODE_75_BINARY_TREE_DFS_LONGEST_ZIGZAG_PATH_IN_A_BINARY_TREE_LONGEST_ZIG_ZAG_PATH_IN_A_BINARY_TREE_H_

// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

enum Direction { LEFT, RIGHT };

class LongestZigZagPathInABinaryTree {
public:
    int longestZigZag(const TreeNode *root) const;

private:
    void maxZigZag(const TreeNode *root, const Direction direction, int &max, int count) const;
};

#endif
