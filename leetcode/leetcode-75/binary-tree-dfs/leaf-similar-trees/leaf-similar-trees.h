#ifndef LEETCODE_LEETCODE_75_BINARY_TREE_DFS_LEAF_SIMILAR_TREES_LEAF_SIMILAR_TREES_H_
#define LEETCODE_LEETCODE_75_BINARY_TREE_DFS_LEAF_SIMILAR_TREES_LEAF_SIMILAR_TREES_H_

// https://leetcode.com/problems/leaf-similar-trees/

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

class LeafSimilarTrees {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) const;

private:
    void traverse(TreeNode *node, std::vector<int> &leaves) const;
};

#endif
