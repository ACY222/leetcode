// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
class Solution {
private:
    struct Amount {
        int no_robbery;
        int robbery;
    };

public:
    int rob(TreeNode* root) {
        Amount total_amount = robOrNot(root);
        return std::max(total_amount.robbery, total_amount.no_robbery);
    }

    Amount robOrNot(TreeNode* curr) {
        if (!curr) {
            return {0, 0};
        }

        Amount left = robOrNot(curr->left);
        Amount right = robOrNot(curr->right);

        int no_robbery = std::max(left.robbery, left.no_robbery) +
            std::max(right.robbery, right.no_robbery);
        int robbery = left.no_robbery + right.no_robbery + curr->val;
        return {no_robbery, robbery};
    }
};
// @leet end
