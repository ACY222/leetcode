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
#include <unordered_map>

using namespace std;

class Solution {
private:
    int dfs(TreeNode* root, long long currSum, int target, unordered_map<long long, int>& prefixSumCount) {
        if (!root) {
            return 0;
        }
        currSum += root->val;

        int count = 0;
        if (prefixSumCount.count(currSum - target)) {
            count = prefixSumCount[currSum - target];
        }

        ++prefixSumCount[currSum];
        count += dfs(root->left, currSum, target, prefixSumCount);
        count += dfs(root->right, currSum, target, prefixSumCount);

        --prefixSumCount[currSum];
        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        return dfs(root, 0, targetSum, prefixSumCount);
    }
};
// @leet end
