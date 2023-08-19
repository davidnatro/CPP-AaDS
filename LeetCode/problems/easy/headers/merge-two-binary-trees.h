#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_MERGE_TWO_BINARY_TREES_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_MERGE_TWO_BINARY_TREES_H_

// https://leetcode.com/problems/merge-two-binary-trees/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
    ~TreeNode();
};

class MergeTwoBinaryTrees {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2);
};

#endif
