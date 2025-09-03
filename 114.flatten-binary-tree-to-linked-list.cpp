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
  // like a preorder traverse
  void flatten(TreeNode* root) {
    if (!root) {
      return;
    }
    traverseAndFlatten(root, nullptr);
  }
private:
  void traverseAndFlatten(TreeNode *curr, TreeNode *parentRightChild) {
    if (!curr) {
      return;
    }
    TreeNode *left {curr->left}, *right {curr->right};
    curr->left = nullptr;
    if (left) {
      curr->right = left;
      // traverse left if left exists
      traverseAndFlatten(left, right ? right : parentRightChild);
    }
    else if (!right) {  // if left and right are both nullptr
      curr->right = parentRightChild;
      return;
    }
    traverseAndFlatten(right, parentRightChild);
  }
};
// @leet end
