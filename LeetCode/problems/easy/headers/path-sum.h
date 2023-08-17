#ifndef LEETCODE_PROBLEMS_EASY_HEADERS_PATH_SUM_H_
#define LEETCODE_PROBLEMS_EASY_HEADERS_PATH_SUM_H_

// https://leetcode.com/problems/path-sum/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
    ~TreeNode();
};

class PathSum {
public:
    bool hasPathSum(TreeNode *root, int targetSum);
};

#endif
