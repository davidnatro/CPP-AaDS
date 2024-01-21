#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_SAME_TREE_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_SAME_TREE_H_

// https://leetcode.com/problems/same-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
    ~TreeNode();
};

class SameTree {
public:
    bool isSameTree(TreeNode *p, TreeNode *q);
};

#endif
