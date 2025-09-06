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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
      return nullptr;
    }
    // if root is right p or q
    if (root == p or root == q) {
      return root;
    }
    // otherwise, root is neither p nor q
    TreeNode* left { lowestCommonAncestor(root->left, p, q) };
    TreeNode* right { lowestCommonAncestor(root->right, p, q) };
    // case 1: if p and q are both in the tree with root "root"
    //  then left and right are p and q
    if (left and right) {
      return root;
    }
    // case 2: if p or q are not in the tree
    if (!left and !right) {
      return nullptr;
    }
    // case 3: if only one of them is in the tree
    return left == nullptr ? right : left;
  }
};
// @leet end
