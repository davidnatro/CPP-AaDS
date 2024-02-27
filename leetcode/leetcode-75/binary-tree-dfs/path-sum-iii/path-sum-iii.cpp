#include "path-sum-iii.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
}

int PathSumIII::pathSum(TreeNode *root, int target_sum) const {
    int64_t prefix_sum = 0;
    std::map<int64_t, int> map;
    map[0] = 1;
    return this->dfs(root, target_sum, map, prefix_sum);
}

int PathSumIII::dfs(TreeNode *root, int target_sum, std::map<int64_t, int> &map,
                    int64_t prefix_sum) const {
    if (root == nullptr) {
        return 0;
    }

    prefix_sum += root->val;
    int result = map[prefix_sum - target_sum];
    map[prefix_sum] += 1;

    result += dfs(root->left, target_sum, map, prefix_sum);
    result += dfs(root->right, target_sum, map, prefix_sum);

    map[prefix_sum] -= 1;

    return result;
}
