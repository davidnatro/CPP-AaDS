#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_DFS_PATH_SUM_III_PATH_SUM_III_H_
#define LEETCODE_LEETCODE_75_BINARY_TREE_DFS_PATH_SUM_III_PATH_SUM_III_H_

// https://leetcode.com/problems/path-sum-iii/

#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

class PathSumIII {
public:
    int pathSum(TreeNode *root, int target_sum) const;

private:
    int dfs(TreeNode *root, int target_sum, std::map<int64_t, int> &map, int64_t prefix_sum) const;
};

#endif
