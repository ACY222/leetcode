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
#include <vector>
using std::vector;
class Solution {
public:
  vector<int> res {};
  vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    traversal(root);
    return res;
  }
private:
  void traversal(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    res.push_back(node->val);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
    return;
  }
};
// @leet end
