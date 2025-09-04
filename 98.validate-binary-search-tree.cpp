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
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return isValid(root, nullptr, nullptr);
  }
private:
  bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
    if (!root) {
      return true;
    }
    if (min and root->val <= min->val) {
      return false;
    }
    if (max and root->val >= max->val) {
      return false;
    }
    return isValid(root->left, min, root) and isValid(root->right, root, max);
  }
};
// @leet end
