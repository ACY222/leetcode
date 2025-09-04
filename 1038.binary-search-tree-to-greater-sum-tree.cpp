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
  int sum {0};
  // inorder traverse works here
  TreeNode* bstToGst(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    bstToGst(root->right);
    int originalSum {sum};
    sum = sum + root->val;
    root->val = root->val + originalSum;
    bstToGst(root->left);
    return root;
  }
};
// @leet end
