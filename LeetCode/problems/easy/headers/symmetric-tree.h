#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_SYMMETRIC_TREE_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_SYMMETRIC_TREE_H_

// https://leetcode.com/problems/symmetric-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
    ~TreeNode();
};

class SymmetricTree {
public:
    bool isSymmetric(TreeNode *root);

private:
    bool isMirror(TreeNode *leftTree, TreeNode *rightTree);
};

#endif
