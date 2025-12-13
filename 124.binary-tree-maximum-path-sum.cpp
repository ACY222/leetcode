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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <algorithm>
using namespace std;

class Solution {
private:
    int max_sum = -1000;
public:
    int maxPathSum(TreeNode* root) {
        int left = maxPathToRootSum(root->left);
        int right = maxPathToRootSum(root->right);

        max_sum = max(max_sum, max(left, 0) + max(right, 0) + root->val);
        return max_sum;
    }

    int maxPathToRootSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = maxPathToRootSum(root->left);
        int right = maxPathToRootSum(root->right);

        max_sum = max(max_sum, max(left, 0) + max(right, 0) + root->val);
        return max(max(left, right), 0) + root->val;
    }
};
// @leet end
