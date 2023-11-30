#include "../headers/merge-two-binary-trees.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

TreeNode *MergeTwoBinaryTrees::mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr) {
        return root2;
    }

    if (root2 == nullptr) {
        return root1;
    }

    TreeNode *head = new TreeNode();

    head->val = root1->val + root2->val;
    head->left = mergeTrees(root1->left, root2->left);
    head->right = mergeTrees(root1->right, root2->right);

    return head;
}