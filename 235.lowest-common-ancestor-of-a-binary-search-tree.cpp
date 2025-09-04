// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  // It's clear that I can use the solution of problem 236 to solve 235.
  // But the BST will give us more information, so we can optimize the solution
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
      return nullptr;
    }
    if (root == p or root == q) {
      return root;
    }
    TreeNode *left, *right;
    // if their values are greater than root->val, they are in right subtree
    if (root->val < p->val and root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    // if their values are less than root->val, they are in left subtree
    else if (root->val > p->val and root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    // otherwise, they are in current tree
    return root;
  }
};
// @leet end
