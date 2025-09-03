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
using std::max;
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (!root) {  // base case: if root == nullptr
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
// @leet end
