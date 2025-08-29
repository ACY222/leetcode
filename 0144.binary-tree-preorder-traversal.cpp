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
#include <stack>
#include <vector>
using std::vector;
using std::stack;
class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node { st.top() };
      st.pop();
      res.push_back(node->val);
      if (node->right) {
        st.push(node->right);
      }
      if (node->left) {
        st.push(node->left);
      }
    }
    return res;
  }
};
// @leet end
